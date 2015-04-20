/* Include files */

#include "blascompat32.h"
#include "testing_control_with_feedback_estimate_sfun.h"
#include "c9_testing_control_with_feedback_estimate.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testing_control_with_feedback_estimate_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[10] = { "dc", "nargin", "nargout",
  "s1", "dc1", "s2", "dc2", "Va", "Vb", "Vc" };

/* Function Declarations */
static void initialize_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void initialize_params_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void enable_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void disable_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_testing_control_with_feedback_estima
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void set_sim_state_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_st);
static void finalize_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void sf_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void initSimStructsc9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_Vc, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_d_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_e_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_b_is_active_c9_testing_control_with_feedback_estimate,
   const char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_testing_control_with_feedback_estimate = 0U;
}

static void initialize_params_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void enable_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_testing_control_with_feedback_estima
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  uint8_T c9_d_hoistedGlobal;
  uint8_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T *c9_Va;
  real_T *c9_Vb;
  real_T *c9_Vc;
  c9_Vc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_Vb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Va = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(4), FALSE);
  c9_hoistedGlobal = *c9_Va;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_Vb;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_Vc;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal =
    chartInstance->c9_is_active_c9_testing_control_with_feedback_estimate;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_Va;
  real_T *c9_Vb;
  real_T *c9_Vc;
  c9_Vc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_Vb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Va = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_Va = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
    "Va");
  *c9_Vb = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "Vb");
  *c9_Vc = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
    "Vc");
  chartInstance->c9_is_active_c9_testing_control_with_feedback_estimate =
    c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
    "is_active_c9_testing_control_with_feedback_estimate");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_testing_control_with_feedback_estima(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void sf_c9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_s1;
  real_T c9_dc1;
  real_T c9_s2;
  real_T c9_dc2;
  uint32_T c9_debug_family_var_map[10];
  real_T c9_dc[3];
  real_T c9_nargin = 4.0;
  real_T c9_nargout = 3.0;
  real_T c9_Va;
  real_T c9_Vb;
  real_T c9_Vc;
  int32_T c9_i0;
  int32_T c9_i1;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  int32_T c9_i2;
  real_T c9_b_u[3];
  const mxArray *c9_b_y = NULL;
  real_T c9_a;
  real_T c9_b_a;
  real_T c9_c_a;
  real_T *c9_b_s1;
  real_T *c9_b_Va;
  real_T *c9_b_dc1;
  real_T *c9_b_s2;
  real_T *c9_b_dc2;
  real_T *c9_b_Vb;
  real_T *c9_b_Vc;
  c9_b_Vc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_Vb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_Va = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_b_s1, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Va, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_dc1, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_b_s2, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_b_dc2, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Vb, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_b_Vc, 6U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_s1;
  c9_b_hoistedGlobal = *c9_b_dc1;
  c9_c_hoistedGlobal = *c9_b_s2;
  c9_d_hoistedGlobal = *c9_b_dc2;
  c9_s1 = c9_hoistedGlobal;
  c9_dc1 = c9_b_hoistedGlobal;
  c9_s2 = c9_c_hoistedGlobal;
  c9_dc2 = c9_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c9_dc, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_s1, 3U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_dc1, 4U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_s2, 5U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_dc2, 6U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_Va, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Vb, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Vc, 9U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i0 = 0; c9_i0 < 3; c9_i0++) {
    c9_dc[c9_i0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  switch ((int32_T)_SFD_INTEGER_CHECK("s1", c9_s1)) {
   case 1:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
    if (CV_EML_IF(0, 1, 0, c9_s2 == 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
      c9_dc[0] = c9_dc1 + c9_dc2;
      c9_dc[1] = c9_dc2;
      c9_dc[2] = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
      c9_dc[0] = c9_dc1 + c9_dc2;
      c9_dc[1] = 0.0;
      c9_dc[2] = c9_dc2;
    }
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
    if (CV_EML_IF(0, 1, 1, c9_s2 == 3.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
      c9_dc[0] = c9_dc1;
      c9_dc[1] = c9_dc1 + c9_dc2;
      c9_dc[2] = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
      c9_dc[0] = c9_dc1 + c9_dc2;
      c9_dc[1] = c9_dc1;
      c9_dc[2] = 0.0;
    }
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
    if (CV_EML_IF(0, 1, 2, c9_s2 == 4.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 28);
      c9_dc[0] = 0.0;
      c9_dc[1] = c9_dc1 + c9_dc2;
      c9_dc[2] = c9_dc2;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 30);
      c9_dc[0] = c9_dc2;
      c9_dc[1] = c9_dc1 + c9_dc2;
      c9_dc[2] = 0.0;
    }
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 33);
    if (CV_EML_IF(0, 1, 3, c9_s2 == 5.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
      c9_dc[0] = 0.0;
      c9_dc[1] = c9_dc1;
      c9_dc[2] = c9_dc1 + c9_dc2;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 36);
      c9_dc[0] = 0.0;
      c9_dc[1] = c9_dc1 + c9_dc2;
      c9_dc[2] = c9_dc1;
      sf_mex_printf("%s =\\n", "dc");
      for (c9_i1 = 0; c9_i1 < 3; c9_i1++) {
        c9_u[c9_i1] = c9_dc[c9_i1];
      }

      c9_y = NULL;
      sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 3),
                    FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c9_y);
    }
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 39);
    if (CV_EML_IF(0, 1, 4, c9_s2 == 6.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 40);
      c9_dc[0] = c9_dc2;
      c9_dc[1] = 0.0;
      c9_dc[2] = c9_dc1 + c9_dc2;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 42);
      c9_dc[0] = 0.0;
      c9_dc[1] = c9_dc2;
      c9_dc[2] = c9_dc1 + c9_dc2;
    }
    break;

   case 6:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
    if (CV_EML_IF(0, 1, 5, c9_s2 == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 47);
      c9_dc[0] = c9_dc1 + c9_dc2;
      c9_dc[1] = 0.0;
      c9_dc[2] = c9_dc1;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 49);
      c9_dc[0] = c9_dc1;
      c9_dc[1] = 0.0;
      c9_dc[2] = c9_dc1 + c9_dc2;
      sf_mex_printf("%s =\\n", "dc");
      for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
        c9_b_u[c9_i2] = c9_dc[c9_i2];
      }

      c9_b_y = NULL;
      sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 2, 1, 3),
                    FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c9_b_y);
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 54);
  c9_a = c9_dc[0];
  c9_Va = c9_a * 12.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 55);
  c9_b_a = c9_dc[1];
  c9_Vb = c9_b_a * 12.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 56);
  c9_c_a = c9_dc[2];
  c9_Vc = c9_c_a * 12.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -56);
  sf_debug_symbol_scope_pop();
  *c9_b_Va = c9_Va;
  *c9_b_Vb = c9_Vb;
  *c9_b_Vc = c9_Vc;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_testing_control_with_feedback_estimateMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_testing_control_with_feedback_estimate
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_Vc, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Vc), &c9_thisId);
  sf_mex_destroy(&c9_Vc);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_Vc;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c9_Vc = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Vc), &c9_thisId);
  sf_mex_destroy(&c9_Vc);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i3;
  real_T c9_b_inData[3];
  int32_T c9_i4;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    c9_b_inData[c9_i3] = (*(real_T (*)[3])c9_inData)[c9_i3];
  }

  for (c9_i4 = 0; c9_i4 < 3; c9_i4++) {
    c9_u[c9_i4] = c9_b_inData[c9_i4];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[3])
{
  real_T c9_dv0[3];
  int32_T c9_i5;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv0, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c9_i5 = 0; c9_i5 < 3; c9_i5++) {
    c9_y[c9_i5] = c9_dv0[c9_i5];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_dc;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i6;
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c9_dc = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_dc), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_dc);
  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    (*(real_T (*)[3])c9_outData)[c9_i6] = c9_y[c9_i6];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray
  *sf_c9_testing_control_with_feedback_estimate_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[1];
  c9_ResolvedFunctionInfo (*c9_b_info)[1];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i7;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_b_info = (c9_ResolvedFunctionInfo (*)[1])c9_info;
  (*c9_b_info)[0].context = "";
  (*c9_b_info)[0].name = "mtimes";
  (*c9_b_info)[0].dominantType = "double";
  (*c9_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c9_b_info)[0].fileTimeLo = 1289541292U;
  (*c9_b_info)[0].fileTimeHi = 0U;
  (*c9_b_info)[0].mFileTimeLo = 0U;
  (*c9_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c9_i7 = 0; c9_i7 < 1; c9_i7++) {
    c9_r0 = &c9_info[c9_i7];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i7);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i7);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_d_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i8;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i8, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i8;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_e_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_b_is_active_c9_testing_control_with_feedback_estimate,
   const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_testing_control_with_feedback_estimate), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_testing_control_with_feedback_estimate);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info
  (SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_testing_control_with_feedback_estimate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1900723322U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2598368747U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(230166865U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(156299461U);
}

mxArray *sf_c9_testing_control_with_feedback_estimate_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("15ntfUQVHTDOw7a2ctDSlF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray
  *sf_get_sim_state_info_c9_testing_control_with_feedback_estimate(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"Va\",},{M[1],M[9],T\"Vb\",},{M[1],M[10],T\"Vc\",},{M[8],M[0],T\"is_active_c9_testing_control_with_feedback_estimate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_testing_control_with_feedback_estimate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
    chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_testing_control_with_feedback_estimateMachineNumber_,
           9,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"s1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Va");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dc1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"s2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dc2");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Vb");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Vc");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1286);
        _SFD_CV_INIT_EML_IF(0,1,0,491,500,541,591);
        _SFD_CV_INIT_EML_IF(0,1,1,611,620,663,713);
        _SFD_CV_INIT_EML_IF(0,1,2,733,742,785,835);
        _SFD_CV_INIT_EML_IF(0,1,3,855,866,909,958);
        _SFD_CV_INIT_EML_IF(0,1,4,978,987,1030,1079);
        _SFD_CV_INIT_EML_IF(0,1,5,1108,1117,1160,1209);

        {
          static int caseStart[] = { 1214, 476, 596, 718, 840, 963, 1084 };

          static int caseExprEnd[] = { 1223, 482, 602, 724, 846, 969, 1090 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,456,466,1236,7,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          real_T *c9_s1;
          real_T *c9_Va;
          real_T *c9_dc1;
          real_T *c9_s2;
          real_T *c9_dc2;
          real_T *c9_Vb;
          real_T *c9_Vc;
          c9_Vc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_Vb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_Va = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_s1);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_Va);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_dc1);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_s2);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_dc2);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_Vb);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_Vc);
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
  return "PpaZoVcJ9x4hjAlEtrQ2cC";
}

static void sf_opaque_initialize_c9_testing_control_with_feedback_estimate(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
  initialize_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c9_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  enable_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c9_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  disable_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c9_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  sf_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c9_testing_control_with_feedback_estimate(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c9_testing_control_with_feedback_estimate();/* state var info */
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

extern void sf_internal_set_sim_state_c9_testing_control_with_feedback_estimate
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
    sf_get_sim_state_info_c9_testing_control_with_feedback_estimate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c9_testing_control_with_feedback_estimate(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_testing_control_with_feedback_estimate(S);
}

static void sf_opaque_set_sim_state_c9_testing_control_with_feedback_estimate
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c9_testing_control_with_feedback_estimate(S, st);
}

static void sf_opaque_terminate_c9_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_testing_control_with_feedback_estimate
      ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_testing_control_with_feedback_estimate_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_testing_control_with_feedback_estimate
    ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_testing_control_with_feedback_estimate
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_testing_control_with_feedback_estimate
      ((SFc9_testing_control_with_feedback_estimateInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_testing_control_with_feedback_estimate(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_testing_control_with_feedback_estimate_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2904769763U));
  ssSetChecksum1(S,(1517947318U));
  ssSetChecksum2(S,(764197135U));
  ssSetChecksum3(S,(173325544U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_testing_control_with_feedback_estimate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_testing_control_with_feedback_estimate(SimStruct *S)
{
  SFc9_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc9_testing_control_with_feedback_estimateInstanceStruct *)
    malloc(sizeof(SFc9_testing_control_with_feedback_estimateInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc9_testing_control_with_feedback_estimateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c9_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_testing_control_with_feedback_estimate;
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

void c9_testing_control_with_feedback_estimate_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_testing_control_with_feedback_estimate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_testing_control_with_feedback_estimate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_testing_control_with_feedback_estimate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_testing_control_with_feedback_estimate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
