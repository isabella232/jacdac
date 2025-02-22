// Autogenerated C header file for Timeseries Aggregator
#ifndef _JACDAC_SPEC_TIMESERIES_AGGREGATOR_H
#define _JACDAC_SPEC_TIMESERIES_AGGREGATOR_H 1

#define JD_SERVICE_CLASS_TIMESERIES_AGGREGATOR  0x1192bdcc

/**
 * No args. Remove all pending timeseries.
 */
#define JD_TIMESERIES_AGGREGATOR_CMD_CLEAR 0x80

/**
 * Add a data point to a timeseries.
 */
#define JD_TIMESERIES_AGGREGATOR_CMD_UPDATE 0x83
typedef struct jd_timeseries_aggregator_update {
    double value;  // f64
    char label[0];  // string
} jd_timeseries_aggregator_update_t;


/**
 * Set aggregation window.
 * Setting to `0` will restore default.
 */
#define JD_TIMESERIES_AGGREGATOR_CMD_SET_WINDOW 0x84
typedef struct jd_timeseries_aggregator_set_window {
    uint32_t duration; // ms
    char label[0];  // string
} jd_timeseries_aggregator_set_window_t;


/**
 * Set whether or not the timeseries will be uploaded to the cloud.
 * The `stored` reports are generated regardless.
 */
#define JD_TIMESERIES_AGGREGATOR_CMD_SET_UPLOAD 0x85
typedef struct jd_timeseries_aggregator_set_upload {
    uint8_t upload;  // bool
    char label[0];  // string
} jd_timeseries_aggregator_set_upload_t;


/**
 * Indicates that the average, minimum and maximum value of a given
 * timeseries are as indicated.
 * It also says how many samples were collected, and the collection period.
 * Timestamps are given using device's internal clock, which will wrap around.
 * Typically, `end_time` can be assumed to be "now".
 * `end_time - start_time == window`
 */
#define JD_TIMESERIES_AGGREGATOR_CMD_STORED 0x90
typedef struct jd_timeseries_aggregator_stored_report {
    uint32_t num_samples; // #
    double avg;  // f64
    double min;  // f64
    double max;  // f64
    uint32_t start_time; // ms
    uint32_t end_time; // ms
    char label[0];  // string
} jd_timeseries_aggregator_stored_report_t;


/**
 * Read-only μs uint32_t. This can queried to establish local time on the device.
 */
#define JD_TIMESERIES_AGGREGATOR_REG_NOW 0x180

/**
 * Read-write bool (uint8_t). When `true`, the windows will be shorter after service reset and gradually extend to requested length.
 * This is ensure valid data is being streamed in program development.
 */
#define JD_TIMESERIES_AGGREGATOR_REG_FAST_START 0x80

/**
 * Read-write ms uint32_t. Window for timeseries for which `set_window` was never called.
 * Note that windows returned initially may be shorter if `fast_start` is enabled.
 */
#define JD_TIMESERIES_AGGREGATOR_REG_DEFAULT_WINDOW 0x81

/**
 * Read-write bool (uint8_t). Whether labelled timeseries for which `set_upload` was never called should be automatically uploaded.
 */
#define JD_TIMESERIES_AGGREGATOR_REG_DEFAULT_UPLOAD 0x82

/**
 * Read-write bool (uint8_t). Whether automatically created timeseries not bound in role manager should be uploaded.
 */
#define JD_TIMESERIES_AGGREGATOR_REG_UPLOAD_UNLABELLED 0x83

/**
 * Read-write ms uint32_t. If no data is received from any sensor within given period, the device is rebooted.
 * Set to `0` to disable (default).
 * Updating user-provided timeseries does not reset the watchdog.
 */
#define JD_TIMESERIES_AGGREGATOR_REG_SENSOR_WATCHDOG_PERIOD 0x84

#endif
