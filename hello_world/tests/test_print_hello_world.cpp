/*================================ FILE INFO =================================*/
/* Filename           : test_print_hello_world.cpp                            */
/*                                                                            */
/* Test implementation for print_hello_world.c                                */
/*                                                                            */
/*============================================================================*/

/*============================================================================*/
/*                               Include Files                                */
/*============================================================================*/
#include <array>
#include <cstdio>
#include <fstream>

extern "C" {
#include "print_hello_world.h"
}

#include <CppUTest/TestHarness.h>

/*============================================================================*/
/*                             Public Definitions                             */
/*============================================================================*/
extern "C"
{

FILE *standard_output{nullptr};
const char TEST_FILE[] = "test_output.txt";

}

void redirect_stdout_to_file(void)
{
    standard_output = stdout;
    CHECK(freopen(TEST_FILE, "w+", stdout) != NULL);
}

void check_printf_output(void)
{
    constexpr std::size_t MAX_BUFFER_SIZE{128};
    std::array<char, MAX_BUFFER_SIZE> buffer{};
    
    FILE *file = fopen("test_output.txt", "r");
    CHECK(file != NULL);
    fread(buffer.data(), sizeof(char), buffer.size(), file);
    fclose(file);
    STRCMP_EQUAL("Hello World\r\n", buffer.data());
}

void restore_stdout(void)
{
    CHECK(stdout != NULL);
    fclose(stdout);
    CHECK(freopen("CON", "w", standard_output) != NULL);
}

/*============================================================================*/
/*                            Mock Implementations                            */
/*============================================================================*/
extern "C"
{

/* none */

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(PrintHelloTest)
{
    

    void setup() override
    {

    }

    void teardown() override
    {

    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(PrintHelloTest, PrintsHelloWorld)
{
    redirect_stdout_to_file();

    print_hello_world();
    fflush(stdout);
    check_printf_output();

    restore_stdout();
}
