/* Include files */

#include "blascompat32.h"
#include "testing_control_with_feedback_estimate_sfun.h"
#include "c8_testing_control_with_feedback_estimate.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testing_control_with_feedback_estimate_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[17] = { "ang", "sext", "v1", "v2",
  "t1", "t2", "num", "den", "nargin", "nargout", "Va", "Vb", "Vdc", "s1", "dc1",
  "s2", "dc2" };

static const char * c8_b_debug_family_names[4] = { "nargin", "nargout", "h", "p"
};

static const char * c8_c_debug_family_names[4] = { "positiveInput", "nargin",
  "nargout", "lambda" };

/* Function Declarations */
static void initialize_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void initialize_params_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void enable_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void disable_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_testing_control_with_feedback_estima
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void set_sim_state_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_st);
static void finalize_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void sf_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void c8_chartstep_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void initSimStructsc8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_dc2, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static creal_T c8_c_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static boolean_T c8_d_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[34]);
static real_T c8_angle(SFc8_testing_control_with_feedback_estimateInstanceStruct
  *chartInstance, creal_T c8_h);
static real_T c8_wrapTo2Pi
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   real_T c8_lambda);
static void c8_pol2cart
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   real_T c8_th, real_T c8_r, real_T *c8_x, real_T *c8_y);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_e_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_f_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_b_is_active_c8_testing_control_with_feedback_estimate,
   const char_T *c8_identifier);
static uint8_T c8_g_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_testing_control_with_feedback_estimate = 0U;
}

static void initialize_params_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void enable_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_testing_control_with_feedback_estima
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_hoistedGlobal;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_d_hoistedGlobal;
  real_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  uint8_T c8_e_hoistedGlobal;
  uint8_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  real_T *c8_dc1;
  real_T *c8_dc2;
  real_T *c8_s1;
  real_T *c8_s2;
  c8_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(5), FALSE);
  c8_hoistedGlobal = *c8_dc1;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_dc2;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *c8_s1;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = *c8_s2;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal =
    chartInstance->c8_is_active_c8_testing_control_with_feedback_estimate;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_dc1;
  real_T *c8_dc2;
  real_T *c8_s1;
  real_T *c8_s2;
  c8_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_dc1 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
    "dc1");
  *c8_dc2 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
    "dc2");
  *c8_s1 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
    "s1");
  *c8_s2 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 3)),
    "s2");
  chartInstance->c8_is_active_c8_testing_control_with_feedback_estimate =
    c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 4)),
    "is_active_c8_testing_control_with_feedback_estimate");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_testing_control_with_feedback_estima(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void sf_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  real_T *c8_Va;
  real_T *c8_s1;
  real_T *c8_dc1;
  real_T *c8_Vb;
  real_T *c8_s2;
  real_T *c8_Vdc;
  real_T *c8_dc2;
  c8_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_Va, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_s1, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_dc1, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_Vb, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_s2, 4U);
  _SFD_DATA_RANGE_CHECK(*c8_Vdc, 5U);
  _SFD_DATA_RANGE_CHECK(*c8_dc2, 6U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_testing_control_with_feedback_estimate(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_testing_control_with_feedback_estimateMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_chartstep_c8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_Va;
  real_T c8_Vb;
  real_T c8_Vdc;
  uint32_T c8_debug_family_var_map[17];
  real_T c8_ang;
  real_T c8_sext;
  creal_T c8_v1;
  creal_T c8_v2;
  real_T c8_t1;
  real_T c8_t2;
  real_T c8_num;
  real_T c8_den;
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 4.0;
  real_T c8_s1;
  real_T c8_dc1;
  real_T c8_s2;
  real_T c8_dc2;
  real_T c8_b;
  static creal_T c8_dc0 = { 0.0, 1.0 };

  creal_T c8_y;
  creal_T c8_b_Va;
  real_T c8_A;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_c_x;
  real_T c8_d_x;
  static creal_T c8_b_dc1 = { 1.0, 1.0 };

  real_T c8_r;
  real_T c8_b_t1;
  real_T c8_b_t2;
  real_T c8_b_b;
  real_T c8_b_r;
  real_T c8_c_t1;
  real_T c8_c_t2;
  real_T c8_c_b;
  real_T c8_c_r;
  real_T c8_d_t1;
  real_T c8_d_t2;
  real_T c8_d_b;
  real_T c8_d_r;
  real_T c8_e_t1;
  real_T c8_e_t2;
  real_T c8_e_b;
  real_T c8_e_r;
  real_T c8_f_t1;
  real_T c8_f_t2;
  real_T c8_f_b;
  real_T c8_g_t2;
  real_T c8_g_t1;
  real_T c8_g_b;
  real_T c8_f_r;
  real_T c8_h_t1;
  real_T c8_h_t2;
  real_T c8_h_b;
  real_T c8_i_t2;
  real_T c8_i_t1;
  real_T c8_i_b;
  real_T c8_j_t2;
  real_T c8_j_t1;
  real_T c8_j_b;
  real_T c8_k_t2;
  real_T c8_k_t1;
  real_T c8_k_b;
  real_T c8_a;
  real_T c8_l_b;
  real_T c8_c_y;
  real_T c8_b_A;
  real_T c8_B;
  real_T c8_e_x;
  real_T c8_d_y;
  real_T c8_f_x;
  real_T c8_e_y;
  real_T c8_f_y;
  real_T c8_b_a;
  real_T c8_m_b;
  real_T c8_g_y;
  real_T c8_c_A;
  real_T c8_b_B;
  real_T c8_g_x;
  real_T c8_h_y;
  real_T c8_h_x;
  real_T c8_i_y;
  real_T c8_j_y;
  real_T c8_d_A;
  real_T c8_c_B;
  real_T c8_i_x;
  real_T c8_k_y;
  real_T c8_j_x;
  real_T c8_l_y;
  real_T c8_c_a;
  real_T c8_n_b;
  real_T c8_m_y;
  real_T c8_e_A;
  real_T c8_d_B;
  real_T c8_k_x;
  real_T c8_n_y;
  real_T c8_l_x;
  real_T c8_o_y;
  real_T *c8_b_dc2;
  real_T *c8_b_s2;
  real_T *c8_c_dc1;
  real_T *c8_b_s1;
  real_T *c8_b_Vdc;
  real_T *c8_b_Vb;
  real_T *c8_c_Va;
  c8_b_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_b_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_b_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_c_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_c_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_c_Va;
  c8_b_hoistedGlobal = *c8_b_Vb;
  c8_c_hoistedGlobal = *c8_b_Vdc;
  c8_Va = c8_hoistedGlobal;
  c8_Vb = c8_b_hoistedGlobal;
  c8_Vdc = c8_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_ang, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_sext, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_v1, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_v2, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_t1, 4U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_t2, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_num, 6U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_den, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 8U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 9U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_Va, 10U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_Vb, 11U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_Vdc, 12U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_s1, 13U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_dc1, 14U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_s2, 15U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_dc2, 16U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  c8_b = c8_Vb;
  c8_y.re = c8_b * c8_dc0.re;
  c8_y.im = c8_b * c8_dc0.im;
  c8_b_Va.re = c8_Va + c8_y.re;
  c8_b_Va.im = c8_y.im;
  c8_ang = c8_wrapTo2Pi(chartInstance, c8_angle(chartInstance, c8_b_Va));
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
  c8_A = c8_ang;
  c8_x = c8_A;
  c8_b_x = c8_x;
  c8_b_y = c8_b_x / 1.0471975511965976;
  c8_c_x = c8_b_y;
  c8_sext = c8_c_x;
  c8_d_x = c8_sext;
  c8_sext = c8_d_x;
  c8_sext = muDoubleScalarFloor(c8_sext);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 13);
  c8_v1 = c8_b_dc1;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
  c8_v2 = c8_b_dc1;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  switch ((int32_T)_SFD_INTEGER_CHECK("sext", c8_sext)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 20);
    c8_s1 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 21);
    c8_v1.re = c8_Vdc;
    c8_v1.im = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 23);
    c8_s2 = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 24);
    c8_r = c8_Vdc;
    c8_b_t1 = c8_r * 0.50000000000000011;
    c8_b_t2 = c8_r * 0.8660254037844386;
    c8_t1 = c8_b_t1;
    c8_t2 = c8_b_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 25);
    c8_b_b = c8_t2;
    c8_y.re = c8_b_b * c8_dc0.re;
    c8_y.im = c8_b_b * c8_dc0.im;
    c8_v2.re = c8_t1 + c8_y.re;
    c8_v2.im = c8_y.im;
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 28);
    c8_s1 = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 29);
    c8_b_r = c8_Vdc;
    c8_c_t1 = c8_b_r * 0.50000000000000011;
    c8_c_t2 = c8_b_r * 0.8660254037844386;
    c8_t1 = c8_c_t1;
    c8_t2 = c8_c_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 30);
    c8_c_b = c8_t2;
    c8_y.re = c8_c_b * c8_dc0.re;
    c8_y.im = c8_c_b * c8_dc0.im;
    c8_v1.re = c8_t1 + c8_y.re;
    c8_v1.im = c8_y.im;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 32);
    c8_s2 = 3.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 33);
    c8_c_r = c8_Vdc;
    c8_d_t1 = c8_c_r * -0.49999999999999978;
    c8_d_t2 = c8_c_r * 0.86602540378443871;
    c8_t1 = c8_d_t1;
    c8_t2 = c8_d_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 34);
    c8_d_b = c8_t2;
    c8_y.re = c8_d_b * c8_dc0.re;
    c8_y.im = c8_d_b * c8_dc0.im;
    c8_v2.re = c8_t1 + c8_y.re;
    c8_v2.im = c8_y.im;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 37);
    c8_s1 = 3.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 38);
    c8_d_r = c8_Vdc;
    c8_e_t1 = c8_d_r * -0.49999999999999978;
    c8_e_t2 = c8_d_r * 0.86602540378443871;
    c8_t1 = c8_e_t1;
    c8_t2 = c8_e_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 39);
    c8_e_b = c8_t2;
    c8_y.re = c8_e_b * c8_dc0.re;
    c8_y.im = c8_e_b * c8_dc0.im;
    c8_v1.re = c8_t1 + c8_y.re;
    c8_v1.im = c8_y.im;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 41);
    c8_s2 = 4.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 42);
    c8_e_r = c8_Vdc;
    c8_f_t1 = -c8_e_r;
    c8_f_t2 = c8_e_r * 1.2246467991473532E-16;
    c8_t1 = c8_f_t1;
    c8_t2 = c8_f_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 43);
    c8_f_b = c8_t2;
    c8_y.re = c8_f_b * c8_dc0.re;
    c8_y.im = c8_f_b * c8_dc0.im;
    c8_v2.re = c8_t1 + c8_y.re;
    c8_v2.im = c8_y.im;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 45);
    c8_s1 = 4.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 46);
    c8_pol2cart(chartInstance, 3.1415926535897931, c8_Vdc, &c8_g_t1, &c8_g_t2);
    c8_t1 = c8_g_t1;
    c8_t2 = c8_g_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 47);
    c8_g_b = c8_t2;
    c8_y.re = c8_g_b * c8_dc0.re;
    c8_y.im = c8_g_b * c8_dc0.im;
    c8_v1.re = c8_t1 + c8_y.re;
    c8_v1.im = c8_y.im;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 49);
    c8_s2 = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 50);
    c8_f_r = c8_Vdc;
    c8_h_t1 = c8_f_r * -0.50000000000000044;
    c8_h_t2 = c8_f_r * -0.86602540378443849;
    c8_t1 = c8_h_t1;
    c8_t2 = c8_h_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 51);
    c8_h_b = c8_t2;
    c8_y.re = c8_h_b * c8_dc0.re;
    c8_y.im = c8_h_b * c8_dc0.im;
    c8_v2.re = c8_t1 + c8_y.re;
    c8_v2.im = c8_y.im;
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 53);
    c8_s1 = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 54);
    c8_pol2cart(chartInstance, 4.1887902047863905, c8_Vdc, &c8_i_t1, &c8_i_t2);
    c8_t1 = c8_i_t1;
    c8_t2 = c8_i_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 55);
    c8_i_b = c8_t2;
    c8_y.re = c8_i_b * c8_dc0.re;
    c8_y.im = c8_i_b * c8_dc0.im;
    c8_v1.re = c8_t1 + c8_y.re;
    c8_v1.im = c8_y.im;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 58);
    c8_s2 = 6.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 59);
    c8_pol2cart(chartInstance, 5.2359877559829888, c8_Vdc, &c8_j_t1, &c8_j_t2);
    c8_t1 = c8_j_t1;
    c8_t2 = c8_j_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 60);
    c8_j_b = c8_t2;
    c8_y.re = c8_j_b * c8_dc0.re;
    c8_y.im = c8_j_b * c8_dc0.im;
    c8_v2.re = c8_t1 + c8_y.re;
    c8_v2.im = c8_y.im;
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 62);
    c8_s1 = 6.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 63);
    c8_pol2cart(chartInstance, 5.2359877559829888, c8_Vdc, &c8_k_t1, &c8_k_t2);
    c8_t1 = c8_k_t1;
    c8_t2 = c8_k_t2;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 64);
    c8_k_b = c8_t2;
    c8_y.re = c8_k_b * c8_dc0.re;
    c8_y.im = c8_k_b * c8_dc0.im;
    c8_v1.re = c8_t1 + c8_y.re;
    c8_v1.im = c8_y.im;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 66);
    c8_s2 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 67);
    c8_v2.re = c8_Vdc;
    c8_v2.im = 0.0;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 69);
    c8_s1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 70);
    c8_s2 = 0.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 74);
  c8_a = c8_v1.im;
  c8_l_b = c8_Va;
  c8_c_y = c8_a * c8_l_b;
  c8_b_A = c8_c_y;
  c8_B = c8_v1.re;
  c8_e_x = c8_b_A;
  c8_d_y = c8_B;
  c8_f_x = c8_e_x;
  c8_e_y = c8_d_y;
  c8_f_y = c8_f_x / c8_e_y;
  c8_num = c8_Vb - c8_f_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 75);
  c8_b_a = c8_v1.im;
  c8_m_b = c8_v2.re;
  c8_g_y = c8_b_a * c8_m_b;
  c8_c_A = c8_g_y;
  c8_b_B = c8_v1.re;
  c8_g_x = c8_c_A;
  c8_h_y = c8_b_B;
  c8_h_x = c8_g_x;
  c8_i_y = c8_h_y;
  c8_j_y = c8_h_x / c8_i_y;
  c8_den = c8_v2.im - c8_j_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 76);
  c8_d_A = c8_num;
  c8_c_B = c8_den;
  c8_i_x = c8_d_A;
  c8_k_y = c8_c_B;
  c8_j_x = c8_i_x;
  c8_l_y = c8_k_y;
  c8_dc2 = c8_j_x / c8_l_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 77);
  c8_c_a = c8_v2.re;
  c8_n_b = c8_dc2;
  c8_m_y = c8_c_a * c8_n_b;
  c8_e_A = c8_Va - c8_m_y;
  c8_d_B = c8_v1.re;
  c8_k_x = c8_e_A;
  c8_n_y = c8_d_B;
  c8_l_x = c8_k_x;
  c8_o_y = c8_n_y;
  c8_dc1 = c8_l_x / c8_o_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -77);
  sf_debug_symbol_scope_pop();
  *c8_b_s1 = c8_s1;
  *c8_c_dc1 = c8_dc1;
  *c8_b_s2 = c8_s2;
  *c8_b_dc2 = c8_dc2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_testing_control_with_feedback_estimate
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_dc2, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_dc2), &c8_thisId);
  sf_mex_destroy(&c8_dc2);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_dc2;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_dc2 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_dc2), &c8_thisId);
  sf_mex_destroy(&c8_dc2);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  creal_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(creal_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static creal_T c8_c_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  creal_T c8_y;
  creal_T c8_dc2;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_dc2, 1, 0, 1U, 0, 0U, 0);
  c8_y = c8_dc2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_v2;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  creal_T c8_y;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_v2 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_v2), &c8_thisId);
  sf_mex_destroy(&c8_v2);
  *(creal_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  boolean_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(boolean_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static boolean_T c8_d_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_y;
  boolean_T c8_b0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b0, 1, 11, 0U, 0, 0U, 0);
  c8_y = c8_b0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_positiveInput;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  boolean_T c8_y;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_positiveInput = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_positiveInput),
    &c8_thisId);
  sf_mex_destroy(&c8_positiveInput);
  *(boolean_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray
  *sf_c8_testing_control_with_feedback_estimate_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[34];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34), FALSE);
  for (c8_i0 = 0; c8_i0 < 34; c8_i0++) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[34])
{
  c8_info[0].context = "";
  c8_info[0].name = "mtimes";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[0].fileTimeLo = 1289541292U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context = "";
  c8_info[1].name = "atan2";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c8_info[1].fileTimeLo = 1286840304U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c8_info[2].name = "eml_scalar_eg";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[2].fileTimeLo = 1286840396U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c8_info[3].name = "eml_scalexp_alloc";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[3].fileTimeLo = 1286840396U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c8_info[4].name = "eml_scalar_atan2";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c8_info[4].fileTimeLo = 1286840320U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "";
  c8_info[5].name = "mod";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[5].fileTimeLo = 1286840344U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[6].name = "eml_scalar_eg";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[6].fileTimeLo = 1286840396U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[7].name = "eml_scalexp_alloc";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[7].fileTimeLo = 1286840396U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c8_info[8].name = "eml_scalar_mod";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c8_info[8].fileTimeLo = 1307672838U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[9].name = "eml_scalar_eg";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[9].fileTimeLo = 1286840396U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[10].name = "eml_scalar_floor";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[10].fileTimeLo = 1286840326U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[11].name = "eml_scalar_round";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c8_info[11].fileTimeLo = 1307672838U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[12].name = "eml_scalar_abs";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[12].fileTimeLo = 1286840312U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[13].name = "eps";
  c8_info[13].dominantType = "char";
  c8_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[13].fileTimeLo = 1307672840U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[14].name = "eml_is_float_class";
  c8_info[14].dominantType = "char";
  c8_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[14].fileTimeLo = 1286840382U;
  c8_info[14].fileTimeHi = 0U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
  c8_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[15].name = "eml_eps";
  c8_info[15].dominantType = "char";
  c8_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[15].fileTimeLo = 1307672840U;
  c8_info[15].fileTimeHi = 0U;
  c8_info[15].mFileTimeLo = 0U;
  c8_info[15].mFileTimeHi = 0U;
  c8_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[16].name = "eml_float_model";
  c8_info[16].dominantType = "char";
  c8_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[16].fileTimeLo = 1307672842U;
  c8_info[16].fileTimeHi = 0U;
  c8_info[16].mFileTimeLo = 0U;
  c8_info[16].mFileTimeHi = 0U;
  c8_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c8_info[17].name = "mtimes";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[17].fileTimeLo = 1289541292U;
  c8_info[17].fileTimeHi = 0U;
  c8_info[17].mFileTimeLo = 0U;
  c8_info[17].mFileTimeHi = 0U;
  c8_info[18].context = "";
  c8_info[18].name = "eml_li_find";
  c8_info[18].dominantType = "";
  c8_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c8_info[18].fileTimeLo = 1286840386U;
  c8_info[18].fileTimeHi = 0U;
  c8_info[18].mFileTimeLo = 0U;
  c8_info[18].mFileTimeHi = 0U;
  c8_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c8_info[19].name = "eml_index_class";
  c8_info[19].dominantType = "";
  c8_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[19].fileTimeLo = 1286840378U;
  c8_info[19].fileTimeHi = 0U;
  c8_info[19].mFileTimeLo = 0U;
  c8_info[19].mFileTimeHi = 0U;
  c8_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c8_info[20].name = "eml_index_class";
  c8_info[20].dominantType = "";
  c8_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[20].fileTimeLo = 1286840378U;
  c8_info[20].fileTimeHi = 0U;
  c8_info[20].mFileTimeLo = 0U;
  c8_info[20].mFileTimeHi = 0U;
  c8_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c8_info[21].name = "eml_index_plus";
  c8_info[21].dominantType = "int32";
  c8_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[21].fileTimeLo = 1286840378U;
  c8_info[21].fileTimeHi = 0U;
  c8_info[21].mFileTimeLo = 0U;
  c8_info[21].mFileTimeHi = 0U;
  c8_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[22].name = "eml_index_class";
  c8_info[22].dominantType = "";
  c8_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[22].fileTimeLo = 1286840378U;
  c8_info[22].fileTimeHi = 0U;
  c8_info[22].mFileTimeLo = 0U;
  c8_info[22].mFileTimeHi = 0U;
  c8_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c8_info[23].name = "eml_index_plus";
  c8_info[23].dominantType = "int32";
  c8_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[23].fileTimeLo = 1286840378U;
  c8_info[23].fileTimeHi = 0U;
  c8_info[23].mFileTimeLo = 0U;
  c8_info[23].mFileTimeHi = 0U;
  c8_info[24].context = "";
  c8_info[24].name = "mrdivide";
  c8_info[24].dominantType = "double";
  c8_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[24].fileTimeLo = 1325145738U;
  c8_info[24].fileTimeHi = 0U;
  c8_info[24].mFileTimeLo = 1319751566U;
  c8_info[24].mFileTimeHi = 0U;
  c8_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[25].name = "rdivide";
  c8_info[25].dominantType = "double";
  c8_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[25].fileTimeLo = 1286840444U;
  c8_info[25].fileTimeHi = 0U;
  c8_info[25].mFileTimeLo = 0U;
  c8_info[25].mFileTimeHi = 0U;
  c8_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[26].name = "eml_div";
  c8_info[26].dominantType = "double";
  c8_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[26].fileTimeLo = 1313369410U;
  c8_info[26].fileTimeHi = 0U;
  c8_info[26].mFileTimeLo = 0U;
  c8_info[26].mFileTimeHi = 0U;
  c8_info[27].context = "";
  c8_info[27].name = "floor";
  c8_info[27].dominantType = "double";
  c8_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[27].fileTimeLo = 1286840342U;
  c8_info[27].fileTimeHi = 0U;
  c8_info[27].mFileTimeLo = 0U;
  c8_info[27].mFileTimeHi = 0U;
  c8_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[28].name = "eml_scalar_floor";
  c8_info[28].dominantType = "double";
  c8_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[28].fileTimeLo = 1286840326U;
  c8_info[28].fileTimeHi = 0U;
  c8_info[28].mFileTimeLo = 0U;
  c8_info[28].mFileTimeHi = 0U;
  c8_info[29].context = "";
  c8_info[29].name = "pol2cart";
  c8_info[29].dominantType = "double";
  c8_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c8_info[29].fileTimeLo = 1286840454U;
  c8_info[29].fileTimeHi = 0U;
  c8_info[29].mFileTimeLo = 0U;
  c8_info[29].mFileTimeHi = 0U;
  c8_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c8_info[30].name = "cos";
  c8_info[30].dominantType = "double";
  c8_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[30].fileTimeLo = 1286840306U;
  c8_info[30].fileTimeHi = 0U;
  c8_info[30].mFileTimeLo = 0U;
  c8_info[30].mFileTimeHi = 0U;
  c8_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[31].name = "eml_scalar_cos";
  c8_info[31].dominantType = "double";
  c8_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c8_info[31].fileTimeLo = 1286840322U;
  c8_info[31].fileTimeHi = 0U;
  c8_info[31].mFileTimeLo = 0U;
  c8_info[31].mFileTimeHi = 0U;
  c8_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c8_info[32].name = "sin";
  c8_info[32].dominantType = "double";
  c8_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[32].fileTimeLo = 1286840350U;
  c8_info[32].fileTimeHi = 0U;
  c8_info[32].mFileTimeLo = 0U;
  c8_info[32].mFileTimeHi = 0U;
  c8_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[33].name = "eml_scalar_sin";
  c8_info[33].dominantType = "double";
  c8_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c8_info[33].fileTimeLo = 1286840336U;
  c8_info[33].fileTimeHi = 0U;
  c8_info[33].mFileTimeLo = 0U;
  c8_info[33].mFileTimeHi = 0U;
}

static real_T c8_angle(SFc8_testing_control_with_feedback_estimateInstanceStruct
  *chartInstance, creal_T c8_h)
{
  real_T c8_p;
  uint32_T c8_debug_family_var_map[4];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_y;
  real_T c8_x;
  real_T c8_b_y;
  real_T c8_b_x;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c8_b_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_h, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_p, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 131U);
  c8_y = c8_h.im;
  c8_x = c8_h.re;
  c8_b_y = c8_y;
  c8_b_x = c8_x;
  c8_p = muDoubleScalarAtan2(c8_b_y, c8_b_x);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -131);
  sf_debug_symbol_scope_pop();
  return c8_p;
}

static real_T c8_wrapTo2Pi
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   real_T c8_lambda)
{
  real_T c8_b_lambda;
  uint32_T c8_debug_family_var_map[4];
  boolean_T c8_positiveInput;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_x;
  real_T c8_xk;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_y;
  real_T c8_g_x;
  real_T c8_b_y;
  real_T c8_b;
  real_T c8_c_y;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T c8_dv0[1];
  boolean_T c8_b1;
  boolean_T c8_b_positiveInput;
  boolean_T c8_j_x;
  boolean_T c8_k_x;
  int32_T c8_k;
  int32_T c8_tmp_sizes[2];
  int32_T c8_iv0[2];
  int32_T c8_i1;
  int32_T c8_i2;
  int32_T c8_loop_ub;
  int32_T c8_i3;
  int32_T c8_tmp_data[1];
  int32_T c8_i4;
  int32_T c8_b_tmp_sizes[2];
  int32_T c8_b_tmp_data[1];
  int32_T c8_b_loop_ub;
  int32_T c8_i5;
  sf_debug_symbol_scope_push_eml(0U, 4U, 5U, c8_c_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_positiveInput, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 2U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_lambda, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_lambda, MAX_uint32_T,
    c8_sf_marshallOut, c8_sf_marshallIn);
  c8_b_lambda = c8_lambda;
  sf_debug_symbol_switch(3U, 4U);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 113);
  c8_positiveInput = (c8_b_lambda > 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 114);
  c8_x = c8_b_lambda;
  c8_xk = c8_x;
  c8_b_x = c8_xk;
  c8_c_x = c8_b_x;
  c8_b_lambda = c8_c_x / 6.2831853071795862;
  c8_d_x = c8_b_lambda;
  c8_e_x = c8_d_x;
  c8_e_x = muDoubleScalarRound(c8_e_x);
  c8_f_x = c8_b_lambda - c8_e_x;
  c8_y = muDoubleScalarAbs(c8_f_x);
  c8_g_x = c8_b_lambda;
  c8_b_y = muDoubleScalarAbs(c8_g_x);
  c8_b = c8_b_y;
  c8_c_y = 2.2204460492503131E-16 * c8_b;
  if (c8_y <= c8_c_y) {
    c8_b_lambda = 0.0;
  } else {
    c8_h_x = c8_b_lambda;
    c8_i_x = c8_h_x;
    c8_i_x = muDoubleScalarFloor(c8_i_x);
    c8_b_lambda = (c8_b_lambda - c8_i_x) * 6.2831853071795862;
  }

  sf_debug_symbol_switch(3U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 115);
  c8_dv0[0] = c8_b_lambda;
  c8_b1 = (c8_b_lambda == 0.0);
  c8_b_positiveInput = c8_positiveInput;
  c8_j_x = (c8_b1 && c8_b_positiveInput);
  c8_k_x = c8_j_x;
  c8_k = 0;
  if (c8_k_x) {
    c8_k = 1;
  }

  c8_tmp_sizes[0] = 1;
  c8_iv0[0] = 1;
  c8_iv0[1] = c8_k;
  c8_tmp_sizes[1] = c8_iv0[1];
  c8_i1 = c8_tmp_sizes[0];
  c8_i2 = c8_tmp_sizes[1];
  c8_loop_ub = c8_k - 1;
  for (c8_i3 = 0; c8_i3 <= c8_loop_ub; c8_i3++) {
    c8_tmp_data[c8_i3] = 0;
  }

  for (c8_i4 = 0; c8_i4 < 2; c8_i4++) {
    c8_b_tmp_sizes[c8_i4] = c8_tmp_sizes[c8_i4];
  }

  if (c8_j_x) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c8_b_tmp_sizes[1], 1, 0);
    c8_b_tmp_data[0] = 1;
  }

  c8_b_loop_ub = c8_b_tmp_sizes[0] * c8_b_tmp_sizes[1] - 1;
  for (c8_i5 = 0; c8_i5 <= c8_b_loop_ub; c8_i5++) {
    c8_dv0[c8_b_tmp_data[c8_i5] - 1] = 6.2831853071795862;
  }

  c8_b_lambda = c8_dv0[0];
  sf_debug_symbol_switch(3U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -115);
  sf_debug_symbol_scope_pop();
  return c8_b_lambda;
}

static void c8_pol2cart
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   real_T c8_th, real_T c8_r, real_T *c8_x, real_T *c8_y)
{
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_e_x;
  c8_b_x = c8_th;
  c8_c_x = c8_b_x;
  c8_c_x = muDoubleScalarCos(c8_c_x);
  *c8_x = c8_r * c8_c_x;
  c8_d_x = c8_th;
  c8_e_x = c8_d_x;
  c8_e_x = muDoubleScalarSin(c8_e_x);
  *c8_y = c8_r * c8_e_x;
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_e_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i6;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i6, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i6;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_f_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_b_is_active_c8_testing_control_with_feedback_estimate,
   const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_testing_control_with_feedback_estimate), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_testing_control_with_feedback_estimate);
  return c8_y;
}

static uint8_T c8_g_emlrt_marshallIn
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance,
   const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info
  (SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_testing_control_with_feedback_estimate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(489747372U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3087332756U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(944003469U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1358036527U);
}

mxArray *sf_c8_testing_control_with_feedback_estimate_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YmHkXMKux7E1Boa3EGZ0u");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray
  *sf_get_sim_state_info_c8_testing_control_with_feedback_estimate(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[9],T\"dc1\",},{M[1],M[10],T\"dc2\",},{M[1],M[5],T\"s1\",},{M[1],M[7],T\"s2\",},{M[8],M[0],T\"is_active_c8_testing_control_with_feedback_estimate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_testing_control_with_feedback_estimate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
    chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_testing_control_with_feedback_estimateMachineNumber_,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Va");
          _SFD_SET_DATA_PROPS(1,2,0,1,"s1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"dc1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Vb");
          _SFD_SET_DATA_PROPS(4,2,0,1,"s2");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Vdc");
          _SFD_SET_DATA_PROPS(6,2,0,1,"dc2");
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
        _SFD_CV_INIT_EML(0,1,3,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2476);
        _SFD_CV_INIT_EML_FCN(0,1,"wrapTo2Pi",2478,-1,3071);
        _SFD_CV_INIT_EML_FCN(0,2,"angle",3073,-1,3429);

        {
          static int caseStart[] = { 1741, 552, 724, 945, 1151, 1357, 1580 };

          static int caseExprEnd[] = { 1750, 558, 730, 951, 1157, 1363, 1586 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,532,544,1798,7,&(caseStart[0]),
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
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);

        {
          real_T *c8_Va;
          real_T *c8_s1;
          real_T *c8_dc1;
          real_T *c8_Vb;
          real_T *c8_s2;
          real_T *c8_Vdc;
          real_T *c8_dc2;
          c8_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c8_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_Va);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_s1);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_dc1);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_Vb);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_s2);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_Vdc);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_dc2);
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
  return "IN0l2tlSbDVdynsfPI5sAC";
}

static void sf_opaque_initialize_c8_testing_control_with_feedback_estimate(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
  initialize_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  enable_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  disable_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  sf_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c8_testing_control_with_feedback_estimate(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c8_testing_control_with_feedback_estimate();/* state var info */
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

extern void sf_internal_set_sim_state_c8_testing_control_with_feedback_estimate
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
    sf_get_sim_state_info_c8_testing_control_with_feedback_estimate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_testing_control_with_feedback_estimate(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_testing_control_with_feedback_estimate(S);
}

static void sf_opaque_set_sim_state_c8_testing_control_with_feedback_estimate
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_testing_control_with_feedback_estimate(S, st);
}

static void sf_opaque_terminate_c8_testing_control_with_feedback_estimate(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_testing_control_with_feedback_estimate
      ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_testing_control_with_feedback_estimate_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_testing_control_with_feedback_estimate
    ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_testing_control_with_feedback_estimate
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_testing_control_with_feedback_estimate
      ((SFc8_testing_control_with_feedback_estimateInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_testing_control_with_feedback_estimate(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_testing_control_with_feedback_estimate_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(74307176U));
  ssSetChecksum1(S,(431819816U));
  ssSetChecksum2(S,(4173236671U));
  ssSetChecksum3(S,(2371865903U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_testing_control_with_feedback_estimate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_testing_control_with_feedback_estimate(SimStruct *S)
{
  SFc8_testing_control_with_feedback_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc8_testing_control_with_feedback_estimateInstanceStruct *)
    malloc(sizeof(SFc8_testing_control_with_feedback_estimateInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc8_testing_control_with_feedback_estimateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_testing_control_with_feedback_estimate;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_testing_control_with_feedback_estimate;
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

void c8_testing_control_with_feedback_estimate_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_testing_control_with_feedback_estimate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_testing_control_with_feedback_estimate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_testing_control_with_feedback_estimate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_testing_control_with_feedback_estimate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
