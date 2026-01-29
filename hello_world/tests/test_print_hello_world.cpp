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
/*                             Private Definitions                            */
/*============================================================================*/
namespace
{

}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(PrintHelloTest)
{
    FILE *standardOutput{nullptr};

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
    constexpr std::size_t MAX_BUFFER_SIZE{128};
    std::array<char, MAX_BUFFER_SIZE> buffer{};

    standardOutput = stdout;
    FILE *spyOutput = freopen("test_output.txt", "w+", stdout);
    CHECK(spyOutput != NULL);

    print_hello_world();

    fflush(stdout);

    FILE *file = fopen("test_output.txt", "r");
    CHECK(file != NULL);

    fread(buffer.data(), sizeof(char), buffer.size(), file);
    fclose(file);

    STRCMP_EQUAL("Hello World\r\n", buffer.data());

    CHECK(stdout != NULL);
    fclose(stdout);
    FILE *restoredOutput = freopen("CON", "w", standardOutput);
    CHECK(restoredOutput != NULL);
}
