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
FILE *standard_output{nullptr};
constexpr const char *TEST_FILE{"test_output.txt"};

void redirect_stdout_to_file(void)
{
    standard_output = stdout;
    CHECK(freopen(TEST_FILE, "w+", stdout) != nullptr);
}

void check_printf_output(void)
{
    constexpr std::size_t kMaxBufferSize = 128;
    std::array<char, kMaxBufferSize> buffer{};

    FILE* file = fopen(TEST_FILE, "r");
    CHECK(file != nullptr);
    const size_t bytes_read =
        fread(buffer.data(), 1, buffer.size() - 1, file);
    CHECK(bytes_read > 0);
    fclose(file);

    STRCMP_EQUAL("Hello World\r\n", buffer.data());
}

void restore_stdout(void)
{
    CHECK(stdout != nullptr);
    fclose(stdout);
    CHECK(freopen("CON", "w", standard_output) != nullptr);
}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(PrintHelloTest)
{
    void setup() override
    {
        redirect_stdout_to_file();
    }

    void teardown() override
    {
        restore_stdout();
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(PrintHelloTest, PrintsHelloWorld)
{
    print_hello_world();
    fflush(stdout);
    check_printf_output();
}
