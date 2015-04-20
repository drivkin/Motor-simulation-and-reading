/* Include files */

#include "blascompat32.h"
#include "testing_control_with_feedback_estimate_sfun.h"
#include "c5_testing_control_with_feedback_estimate.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testing_control_with_feedback_estimate_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[5] = { "positiveInput", "nargin",
  "nargout", "lambda", "lambda1" };

/* Function Declarations */
static void initialize_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void initialize_params_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void enable_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void disable_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_testing_control_with_feedback_estima
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void set_sim_state_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_st);
static void finalize_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void sf_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void c5_chartstep_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void initSimStructsc5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_lambda1, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static boolean_T c5_c_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[20]);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_b_is_active_c5_testing_control_with_feedback_estimate,
   const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_testing_control_with_feedback_estimate = 0U;
}

static void initialize_params_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void enable_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_testing_control_with_feedback_estima
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_lambda1;
  c5_lambda1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  c5_hoistedGlobal = *c5_lambda1;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal =
    chartInstance->c5_is_active_c5_testing_control_with_feedback_estimate;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_lambda1;
  c5_lambda1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_lambda1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 0)), "lambda1");
  chartInstance->c5_is_active_c5_testing_control_with_feedback_estimate =
    c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "is_active_c5_testing_control_with_feedback_estimate");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_testing_control_with_feedback_estima(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void sf_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  real_T *c5_lambda;
  real_T *c5_lambda1;
  c5_lambda1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_lambda = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_lambda, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_lambda1, 1U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_testing_control_with_feedback_estimate(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_testing_control_with_feedback_estimateMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_lambda;
  uint32_T c5_debug_family_var_map[5];
  boolean_T c5_positiveInput;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  real_T c5_lambda1;
  real_T c5_x;
  real_T c5_xk;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_y;
  real_T c5_g_x;
  real_T c5_b_y;
  real_T c5_b;
  real_T c5_c_y;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_dv0[1];
  boolean_T c5_b0;
  boolean_T c5_b_positiveInput;
  boolean_T c5_j_x;
  boolean_T c5_k_x;
  int32_T c5_k;
  int32_T c5_tmp_sizes[2];
  int32_T c5_iv0[2];
  int32_T c5_i0;
  int32_T c5_i1;
  int32_T c5_loop_ub;
  int32_T c5_i2;
  int32_T c5_tmp_data[1];
  int32_T c5_i3;
  int32_T c5_b_tmp_sizes[2];
  int32_T c5_b_tmp_data[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i4;
  real_T *c5_b_lambda1;
  real_T *c5_b_lambda;
  c5_b_lambda1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_lambda = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_lambda;
  c5_lambda = c5_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_positiveInput, 0U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_lambda, 3U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_lambda1, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_positiveInput = (c5_lambda > 0.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_x = c5_lambda;
  c5_xk = c5_x;
  c5_b_x = c5_xk;
  c5_c_x = c5_b_x;
  c5_lambda = c5_c_x / 6.2831853071795862;
  c5_d_x = c5_lambda;
  c5_e_x = c5_d_x;
  c5_e_x = muDoubleScalarRound(c5_e_x);
  c5_f_x = c5_lambda - c5_e_x;
  c5_y = muDoubleScalarAbs(c5_f_x);
  c5_g_x = c5_lambda;
  c5_b_y = muDoubleScalarAbs(c5_g_x);
  c5_b = c5_b_y;
  c5_c_y = 2.2204460492503131E-16 * c5_b;
  if (c5_y <= c5_c_y) {
    c5_lambda = 0.0;
  } else {
    c5_h_x = c5_lambda;
    c5_i_x = c5_h_x;
    c5_i_x = muDoubleScalarFloor(c5_i_x);
    c5_lambda = (c5_lambda - c5_i_x) * 6.2831853071795862;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_dv0[0] = c5_lambda;
  c5_b0 = (c5_lambda == 0.0);
  c5_b_positiveInput = c5_positiveInput;
  c5_j_x = (c5_b0 && c5_b_positiveInput);
  c5_k_x = c5_j_x;
  c5_k = 0;
  if (c5_k_x) {
    c5_k = 1;
  }

  c5_tmp_sizes[0] = 1;
  c5_iv0[0] = 1;
  c5_iv0[1] = c5_k;
  c5_tmp_sizes[1] = c5_iv0[1];
  c5_i0 = c5_tmp_sizes[0];
  c5_i1 = c5_tmp_sizes[1];
  c5_loop_ub = c5_k - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_tmp_data[c5_i2] = 0;
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_b_tmp_sizes[c5_i3] = c5_tmp_sizes[c5_i3];
  }

  if (c5_j_x) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c5_b_tmp_sizes[1], 1, 0);
    c5_b_tmp_data[0] = 1;
  }

  c5_b_loop_ub = c5_b_tmp_sizes[0] * c5_b_tmp_sizes[1] - 1;
  for (c5_i4 = 0; c5_i4 <= c5_b_loop_ub; c5_i4++) {
    c5_dv0[c5_b_tmp_data[c5_i4] - 1] = 6.2831853071795862;
  }

  c5_lambda = c5_dv0[0];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_lambda1 = c5_lambda;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -18);
  sf_debug_symbol_scope_pop();
  *c5_b_lambda1 = c5_lambda1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_testing_control_with_feedback_estimate
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_lambda1, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_lambda1), &c5_thisId);
  sf_mex_destroy(&c5_lambda1);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_lambda1;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c5_lambda1 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_lambda1), &c5_thisId);
  sf_mex_destroy(&c5_lambda1);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(boolean_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static boolean_T c5_c_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_y;
  boolean_T c5_b1;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b1, 1, 11, 0U, 0, 0U, 0);
  c5_y = c5_b1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_positiveInput;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_y;
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c5_positiveInput = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_positiveInput),
    &c5_thisId);
  sf_mex_destroy(&c5_positiveInput);
  *(boolean_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray
  *sf_c5_testing_control_with_feedback_estimate_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[20];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i5;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c5_i5 = 0; c5_i5 < 20; c5_i5++) {
    c5_r0 = &c5_info[c5_i5];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i5);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i5);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[20])
{
  c5_info[0].context = "";
  c5_info[0].name = "mtimes";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[0].fileTimeLo = 1289541292U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context = "";
  c5_info[1].name = "mod";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[1].fileTimeLo = 1286840344U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[2].name = "eml_scalar_eg";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[2].fileTimeLo = 1286840396U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[3].name = "eml_scalexp_alloc";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[3].fileTimeLo = 1286840396U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c5_info[4].name = "eml_scalar_mod";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c5_info[4].fileTimeLo = 1307672838U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c5_info[5].name = "eml_scalar_eg";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[5].fileTimeLo = 1286840396U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c5_info[6].name = "eml_scalar_floor";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[6].fileTimeLo = 1286840326U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c5_info[7].name = "eml_scalar_round";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c5_info[7].fileTimeLo = 1307672838U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c5_info[8].name = "eml_scalar_abs";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[8].fileTimeLo = 1286840312U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c5_info[9].name = "eps";
  c5_info[9].dominantType = "char";
  c5_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[9].fileTimeLo = 1307672840U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[10].name = "eml_is_float_class";
  c5_info[10].dominantType = "char";
  c5_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[10].fileTimeLo = 1286840382U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[11].name = "eml_eps";
  c5_info[11].dominantType = "char";
  c5_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[11].fileTimeLo = 1307672840U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[12].name = "eml_float_model";
  c5_info[12].dominantType = "char";
  c5_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c5_info[12].fileTimeLo = 1307672842U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c5_info[13].name = "mtimes";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[13].fileTimeLo = 1289541292U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context = "";
  c5_info[14].name = "eml_li_find";
  c5_info[14].dominantType = "";
  c5_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c5_info[14].fileTimeLo = 1286840386U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c5_info[15].name = "eml_index_class";
  c5_info[15].dominantType = "";
  c5_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[15].fileTimeLo = 1286840378U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c5_info[16].name = "eml_index_class";
  c5_info[16].dominantType = "";
  c5_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[16].fileTimeLo = 1286840378U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c5_info[17].name = "eml_index_plus";
  c5_info[17].dominantType = "int32";
  c5_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[17].fileTimeLo = 1286840378U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[18].name = "eml_index_class";
  c5_info[18].dominantType = "";
  c5_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[18].fileTimeLo = 1286840378U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c5_info[19].name = "eml_index_plus";
  c5_info[19].dominantType = "int32";
  c5_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[19].fileTimeLo = 1286840378U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i6;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i6, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i6;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_b_is_active_c5_testing_control_with_feedback_estimate,
   const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_testing_control_with_feedback_estimate), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_testing_control_with_feedback_estimate);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info
  (SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_testing_control_with_feedback_estimate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2994947464U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(245701684U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1680239668U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2070991703U);
}

mxArray *sf_c5_testing_control_with_feedback_estimate_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dxN03vC2tBjZX04T0oOSrC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray
  *sf_get_sim_state_info_c5_testing_control_with_feedback_estimate(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"lambda1\",},{M[8],M[0],T\"is_active_c5_testing_control_with_feedback_estimate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_testing_control_with_feedback_estimate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
    chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_testing_control_with_feedback_estimateMachineNumber_,
           5,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_testing_control_with_feedback_estimateMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_testing_control_with_feedback_estimateMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_testing_control_with_feedback_estimateMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"lambda");
          _SFD_SET_DATA_PROPS(1,2,0,1,"lambda1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,611);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          real_T *c5_lambda;
          real_T *c5_lambda1;
          c5_lambda1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_lambda = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_lambda);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_lambda1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_testing_control_with_feedback_estimateMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "63GfgP0VVLajwfS58MqDlH";
}

static void sf_opaque_initialize_c5_testing_control_with_feedback_estimate(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
  initialize_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c5_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  enable_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c5_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  disable_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c5_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  sf_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c5_testing_control_with_feedback_estimate(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c5_testing_control_with_feedback_estimate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_testing_control_with_feedback_estimate
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c5_testing_control_with_feedback_estimate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c5_testing_control_with_feedback_estimate(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_testing_control_with_feedback_estimate(S);
}

static void sf_opaque_set_sim_state_c5_testing_control_with_feedback_estimate
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_testing_control_with_feedback_estimate(S, st);
}

static void sf_opaque_terminate_c5_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_testing_control_with_feedback_estimate
      ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_testing_control_with_feedback_estimate_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_testing_control_with_feedback_estimate
    ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_testing_control_with_feedback_estimate
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_testing_control_with_feedback_estimate
      ((SFc5_testing_control_with_feedback_estimateInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_testing_control_with_feedback_estimate(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_testing_control_with_feedback_estimate_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3088695024U));
  ssSetChecksum1(S,(1783995608U));
  ssSetChecksum2(S,(517872383U));
  ssSetChecksum3(S,(1103525791U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_testing_control_with_feedback_estimate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_testing_control_with_feedback_estimate(SimStruct *S)
{
  SFc5_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc5_testing_control_with_feedback_estimateInstanceStruct *)
    malloc(sizeof(SFc5_testing_control_with_feedback_estimateInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc5_testing_control_with_feedback_estimateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_testing_control_with_feedback_estimate_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_testing_control_with_feedback_estimate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_testing_control_with_feedback_estimate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_testing_control_with_feedback_estimate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_testing_control_with_feedback_estimate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
