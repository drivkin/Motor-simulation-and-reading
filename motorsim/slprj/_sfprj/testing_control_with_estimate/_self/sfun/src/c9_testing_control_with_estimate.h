#ifndef __c9_testing_control_with_estimate_h__
#define __c9_testing_control_with_estimate_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c9_ResolvedFunctionInfo;

typedef struct {
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_testing_control_with_estimate;
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc9_testing_control_with_estimateInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_testing_control_with_estimate_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_testing_control_with_estimate_get_check_sum(mxArray *plhs[]);
extern void c9_testing_control_with_estimate_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
