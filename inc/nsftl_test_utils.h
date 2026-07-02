#ifndef __NSFT_TEST_UTILS_H__
#define __NSFT_TEST_UTILS_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @author Diego Graziati
 * 
 * @brief This function starts the test report's timer.
 * 
 * @param[in] report This is the target test report. At the end it will have a new start_time value
 * 
 * @retval NSFTL_TEST_REPORT_NOT_INITIALIZED If parameter report hasn't been initialized before.
 * @retval NSFTL_TEST_REPORT_START_TIME_NOT_INITIALIZED If parameter report's start_time member hasn't been initialied before.
 * @retval NSFTL_UNABLE_TO_RETRIEVE_CLOCK_TIME If parameter report's hasn't been initialized before. Normally, if this condition is true the value returned should be NSFTL_REST_REPORT_NOT_INITIALIZED!
 * @retval NSFTL_TEST_REPORT_FAILED_TO_GET_CLOCK_TIME If the internal function call "nsftl_getclock_time" fails to retrieve the actual clock time through the OS's API.
 * @retval NSFTL_SUCCESS Everything went right.
 */
nsftl_status_t nsftl_start_report_timer (nsftl_test_report_t report);

/**
 * @author Diego Graziati
 * 
 * @brief This function stops the test report's timer.
 * 
 * @param[in] report This is the target test report. At the end it will have a new end_time value
 * 
 * @retval NSFTL_TEST_REPORT_NOT_INITIALIZED If parameter report hasn't been initialized before.
 * @retval NSFTL_TEST_REPORT_START_TIME_NOT_INITIALIZED If parameter report's end_time member hasn't been initialied before.
 * @retval NSFTL_UNABLE_TO_RETRIEVE_CLOCK_TIME If parameter report hasn't been initialized before. Normally, if this condition is true the value returned should be NSFTL_REST_REPORT_NOT_INITIALIZED!
 * @retval NSFTL_TEST_REPORT_FAILED_TO_GET_CLOCK_TIME If the internal function call "nsftl_getclock_time" fails to retrieve the actual clock time through the OS's API.
 * @retval NSFTL_SUCCESS Everything went right.
 */
nsftl_status_t nsftl_stop_report_timer (nsftl_test_report_t report);

/**
 * @author Diego Graziati
 * 
 * @brief This function handles all memory related matters when writing a report, returning it directly to you.
 * 
 * @param[in] report It is the report you want to write. It should already be initialized.
 * @param[in] message It is the sentence that needs to be written inside the report.
 * @param[in] message_length It is the report's message length. It must not be bigger than or equal to MYTEST_TEST_REPORT_MAX_MESSAGE_LENGTH.
 * @param[in] status The test return status after its execution.
 * 
 * @retval NSFTL_MEMORY_ALLOCATION_FAILED_MEMORY_INSUFFICIENT If the function fails to allocate memory at any point.
 * @retval NSFTL_REPORT_MESSAGE_IS_TOO_LONG If the passed message is longer than NSFTL_TEST_REPORT_MAX_MESSAGE_LENGTH characters.
 * @retval NSFTL_SUCCESS Everything went right.
 */
nsftl_status_t nsftl_write_report (nsftl_test_report_t* report, const char* message,  size_t message_length, nsftl_status_t status);

/**
 * @author Diego Graziati
 * 
 * @brief This function handles the test function callback assignment to the test unit passed as argument.
 * 
 * @param[in] test_unit This is the test unit target. At the end it will have a test_call_fn attached to it.
 * @param[in] test_callback_fn The test function defined by the user.
 * 
 * @retval NSFTL_UNABLE_TO_SUBMIT_TEST_FUNCTION_TO_TEST_UNIT If the function fails to link the test_callback_fn to the test_unit.
 * @retval NSFTL_SUCCESS Everything went right.
 */
nsftl_status_t nsftl_submit_test_to_test_unit (nsftl_test_unit_t test_unit, void (*test_callback_fn)(nsftl_test_report_t* test_report, nsftl_index_t index));

#ifdef __cplusplus
}
#endif

#endif