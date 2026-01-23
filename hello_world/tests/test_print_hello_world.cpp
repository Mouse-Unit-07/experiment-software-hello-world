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
void failWithMessageIfNull(const void *file, const char *message)
{
    if (file == nullptr) {
        FAIL(message);
    }
}
}

/*============================================================================*/
/*                                 Test Group                                 */
/*============================================================================*/
TEST_GROUP(PrintHelloTest)
{
    FILE *originalOutput{nullptr};

    void setup() override
    {
        originalOutput = stdout;
        FILE *spy_output = freopen("test_output.txt", "w+", stdout);
        failWithMessageIfNull(spy_output, 
            "Failed to redirect stdout to test_output.txt");
    }

    void teardown() override
    {
        failWithMessageIfNull(stdout, "stdout is nullptr");
        fclose(stdout);
        FILE *restoredOutput = freopen("CON", "w", originalOutput);
        failWithMessageIfNull(restoredOutput,
            "Failed to restore stdout to console");
    }
};

/*============================================================================*/
/*                                    Tests                                   */
/*============================================================================*/
TEST(PrintHelloTest, PrintsHelloWorld)
{
    constexpr std::size_t MAX_BUFFER_SIZE{128};
    std::array<char, MAX_BUFFER_SIZE> buffer{};

    printHelloWorld();

    fflush(stdout);

    FILE *file = fopen("test_output.txt", "r");
    failWithMessageIfNull(file, "Failed to open test output file");

    fread(buffer.data(), sizeof(char), buffer.size(), file);
    fclose(file);

    STRCMP_EQUAL("Hello World\r\n", buffer.data());
}
