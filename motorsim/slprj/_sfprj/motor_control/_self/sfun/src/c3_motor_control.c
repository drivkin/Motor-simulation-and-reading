/* Include files */

#include "blascompat32.h"
#include "motor_control_sfun.h"
#include "c3_motor_control.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "motor_control_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[22] = { "ang", "sext", "v1", "v2",
  "t1", "t2", "num", "den", "xint", "yint", "nargin", "nargout", "Va", "Vb",
  "Vdc", "tracking", "theta", "DTorque", "s1", "dc1", "s2", "dc2" };

static const char * c3_b_debug_family_names[4] = { "nargin", "nargout", "h", "p"
};

static const char * c3_c_debug_family_names[4] = { "positiveInput", "nargin",
  "nargout", "lambda" };

/* Function Declarations */
static void initialize_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance);
static void initialize_params_c3_motor_control(SFc3_motor_controlInstanceStruct *
  chartInstance);
static void enable_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance);
static void disable_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_motor_control
  (SFc3_motor_controlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_motor_control
  (SFc3_motor_controlInstanceStruct *chartInstance);
static void set_sim_state_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance);
static void sf_c3_motor_control(SFc3_motor_controlInstanceStruct *chartInstance);
static void c3_chartstep_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance);
static void initSimStructsc3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_dc2, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static creal_T c3_c_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_d_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[42]);
static real_T c3_angle(SFc3_motor_controlInstanceStruct *chartInstance, creal_T
  c3_h);
static real_T c3_wrapTo2Pi(SFc3_motor_controlInstanceStruct *chartInstance,
  real_T c3_lambda);
static void c3_pol2cart(SFc3_motor_controlInstanceStruct *chartInstance, real_T
  c3_th, real_T c3_r, real_T *c3_x, real_T *c3_y);
static real_T c3_mpower(SFc3_motor_controlInstanceStruct *chartInstance, real_T
  c3_a);
static real_T c3_sqrt(SFc3_motor_controlInstanceStruct *chartInstance, real_T
                      c3_x);
static void c3_eml_error(SFc3_motor_controlInstanceStruct *chartInstance);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_motor_control, const char_T
  *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sqrt(SFc3_motor_controlInstanceStruct *chartInstance, real_T
                      *c3_x);
static void init_dsm_address_info(SFc3_motor_controlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_motor_control = 0U;
}

static void initialize_params_c3_motor_control(SFc3_motor_controlInstanceStruct *
  chartInstance)
{
}

static void enable_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_motor_control
  (SFc3_motor_controlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_motor_control
  (SFc3_motor_controlInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T *c3_dc1;
  real_T *c3_dc2;
  real_T *c3_s1;
  real_T *c3_s2;
  c3_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(5), FALSE);
  c3_hoistedGlobal = *c3_dc1;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_dc2;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_s1;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_s2;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_motor_control;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_dc1;
  real_T *c3_dc2;
  real_T *c3_s1;
  real_T *c3_s2;
  c3_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_dc1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "dc1");
  *c3_dc2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "dc2");
  *c3_s1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "s1");
  *c3_s2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "s2");
  chartInstance->c3_is_active_c3_motor_control = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
     "is_active_c3_motor_control");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_motor_control(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
}

static void sf_c3_motor_control(SFc3_motor_controlInstanceStruct *chartInstance)
{
  real_T *c3_Va;
  real_T *c3_s1;
  real_T *c3_dc1;
  real_T *c3_Vb;
  real_T *c3_s2;
  real_T *c3_Vdc;
  real_T *c3_dc2;
  real_T *c3_tracking;
  real_T *c3_theta;
  real_T *c3_DTorque;
  c3_DTorque = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_tracking = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_Va, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_s1, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_dc1, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_Vb, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_s2, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_Vdc, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_dc2, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_tracking, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_theta, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_DTorque, 9U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_motor_control(chartInstance);
  sf_debug_check_for_state_inconsistency(_motor_controlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_Va;
  real_T c3_Vb;
  real_T c3_Vdc;
  real_T c3_tracking;
  real_T c3_theta;
  real_T c3_DTorque;
  uint32_T c3_debug_family_var_map[22];
  real_T c3_ang;
  real_T c3_sext;
  creal_T c3_v1;
  creal_T c3_v2;
  real_T c3_t1;
  real_T c3_t2;
  real_T c3_num;
  real_T c3_den;
  real_T c3_xint;
  real_T c3_yint;
  real_T c3_nargin = 6.0;
  real_T c3_nargout = 4.0;
  real_T c3_s1;
  real_T c3_dc1;
  real_T c3_s2;
  real_T c3_dc2;
  real_T c3_b;
  static creal_T c3_dc0 = { 0.0, 1.0 };

  creal_T c3_y;
  creal_T c3_b_Va;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_d_x;
  static creal_T c3_b_dc1 = { 1.0, 1.0 };

  real_T c3_b_t2;
  real_T c3_b_t1;
  real_T c3_b_b;
  real_T c3_c_t2;
  real_T c3_c_t1;
  real_T c3_c_b;
  real_T c3_d_t2;
  real_T c3_d_t1;
  real_T c3_d_b;
  real_T c3_e_t2;
  real_T c3_e_t1;
  real_T c3_e_b;
  real_T c3_f_t2;
  real_T c3_f_t1;
  real_T c3_f_b;
  real_T c3_g_t2;
  real_T c3_g_t1;
  real_T c3_g_b;
  real_T c3_h_t2;
  real_T c3_h_t1;
  real_T c3_h_b;
  real_T c3_i_t2;
  real_T c3_i_t1;
  real_T c3_i_b;
  real_T c3_j_t2;
  real_T c3_j_t1;
  real_T c3_j_b;
  real_T c3_k_t2;
  real_T c3_k_t1;
  real_T c3_k_b;
  real_T c3_a;
  real_T c3_l_b;
  real_T c3_c_y;
  real_T c3_b_A;
  real_T c3_B;
  real_T c3_e_x;
  real_T c3_d_y;
  real_T c3_f_x;
  real_T c3_e_y;
  real_T c3_f_y;
  real_T c3_c_A;
  real_T c3_b_B;
  real_T c3_g_x;
  real_T c3_g_y;
  real_T c3_h_x;
  real_T c3_h_y;
  real_T c3_i_y;
  real_T c3_d_A;
  real_T c3_c_B;
  real_T c3_i_x;
  real_T c3_j_y;
  real_T c3_j_x;
  real_T c3_k_y;
  real_T c3_e_A;
  real_T c3_d_B;
  real_T c3_k_x;
  real_T c3_l_y;
  real_T c3_l_x;
  real_T c3_m_y;
  real_T c3_n_y;
  real_T c3_b_a;
  real_T c3_m_b;
  real_T c3_f_A;
  real_T c3_e_B;
  real_T c3_m_x;
  real_T c3_o_y;
  real_T c3_n_x;
  real_T c3_p_y;
  real_T c3_g_A;
  real_T c3_f_B;
  real_T c3_o_x;
  real_T c3_q_y;
  real_T c3_p_x;
  real_T c3_r_y;
  real_T c3_h_A;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_y;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_i_A;
  real_T c3_g_B;
  real_T c3_u_x;
  real_T c3_t_y;
  real_T c3_v_x;
  real_T c3_u_y;
  real_T *c3_b_dc2;
  real_T *c3_b_s2;
  real_T *c3_c_dc1;
  real_T *c3_b_s1;
  real_T *c3_b_DTorque;
  real_T *c3_b_theta;
  real_T *c3_b_tracking;
  real_T *c3_b_Vdc;
  real_T *c3_b_Vb;
  real_T *c3_c_Va;
  c3_b_DTorque = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_tracking = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_c_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_c_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_c_Va;
  c3_b_hoistedGlobal = *c3_b_Vb;
  c3_c_hoistedGlobal = *c3_b_Vdc;
  c3_d_hoistedGlobal = *c3_b_tracking;
  c3_e_hoistedGlobal = *c3_b_theta;
  c3_f_hoistedGlobal = *c3_b_DTorque;
  c3_Va = c3_hoistedGlobal;
  c3_Vb = c3_b_hoistedGlobal;
  c3_Vdc = c3_c_hoistedGlobal;
  c3_tracking = c3_d_hoistedGlobal;
  c3_theta = c3_e_hoistedGlobal;
  c3_DTorque = c3_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 22U, 22U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_ang, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_sext, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_v1, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_v2, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_t1, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_t2, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_num, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_den, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_xint, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_yint, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_Va, 12U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Vb, 13U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Vdc, 14U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_tracking, 15U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_theta, 16U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_DTorque, 17U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_s1, 18U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dc1, 19U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_s2, 20U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_dc2, 21U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c3_tracking == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
    c3_b = c3_Vb;
    c3_y.re = c3_b * c3_dc0.re;
    c3_y.im = c3_b * c3_dc0.im;
    c3_b_Va.re = c3_Va + c3_y.re;
    c3_b_Va.im = c3_y.im;
    c3_ang = c3_wrapTo2Pi(chartInstance, c3_angle(chartInstance, c3_b_Va));
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
    c3_A = c3_ang;
    c3_x = c3_A;
    c3_b_x = c3_x;
    c3_b_y = c3_b_x / 1.0471975511965976;
    c3_c_x = c3_b_y;
    c3_sext = c3_c_x;
    c3_d_x = c3_sext;
    c3_sext = c3_d_x;
    c3_sext = muDoubleScalarFloor(c3_sext);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
    c3_v1 = c3_b_dc1;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
    c3_v2 = c3_b_dc1;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
    switch ((int32_T)_SFD_INTEGER_CHECK("sext", c3_sext)) {
     case 0:
      CV_EML_SWITCH(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
      c3_s1 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
      c3_v1.re = c3_Vdc;
      c3_v1.im = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
      c3_s2 = 2.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
      c3_pol2cart(chartInstance, c3_Vdc, 1.0471975511965976, &c3_b_t1, &c3_b_t2);
      c3_t1 = c3_b_t1;
      c3_t2 = c3_b_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
      c3_b_b = c3_t2;
      c3_y.re = c3_b_b * c3_dc0.re;
      c3_y.im = c3_b_b * c3_dc0.im;
      c3_v2.re = c3_t1 + c3_y.re;
      c3_v2.im = c3_y.im;
      break;

     case 1:
      CV_EML_SWITCH(0, 1, 0, 2);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
      c3_s1 = 2.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
      c3_pol2cart(chartInstance, c3_Vdc, 1.0471975511965976, &c3_c_t1, &c3_c_t2);
      c3_t1 = c3_c_t1;
      c3_t2 = c3_c_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
      c3_c_b = c3_t2;
      c3_y.re = c3_c_b * c3_dc0.re;
      c3_y.im = c3_c_b * c3_dc0.im;
      c3_v1.re = c3_t1 + c3_y.re;
      c3_v1.im = c3_y.im;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
      c3_s2 = 3.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
      c3_pol2cart(chartInstance, c3_Vdc, 2.0943951023931953, &c3_d_t1, &c3_d_t2);
      c3_t1 = c3_d_t1;
      c3_t2 = c3_d_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
      c3_d_b = c3_t2;
      c3_y.re = c3_d_b * c3_dc0.re;
      c3_y.im = c3_d_b * c3_dc0.im;
      c3_v2.re = c3_t1 + c3_y.re;
      c3_v2.im = c3_y.im;
      break;

     case 2:
      CV_EML_SWITCH(0, 1, 0, 3);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
      c3_s1 = 3.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
      c3_pol2cart(chartInstance, c3_Vdc, 2.0943951023931953, &c3_e_t1, &c3_e_t2);
      c3_t1 = c3_e_t1;
      c3_t2 = c3_e_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
      c3_e_b = c3_t2;
      c3_y.re = c3_e_b * c3_dc0.re;
      c3_y.im = c3_e_b * c3_dc0.im;
      c3_v1.re = c3_t1 + c3_y.re;
      c3_v1.im = c3_y.im;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
      c3_s2 = 4.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
      c3_pol2cart(chartInstance, c3_Vdc, 3.1415926535897931, &c3_f_t1, &c3_f_t2);
      c3_t1 = c3_f_t1;
      c3_t2 = c3_f_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
      c3_f_b = c3_t2;
      c3_y.re = c3_f_b * c3_dc0.re;
      c3_y.im = c3_f_b * c3_dc0.im;
      c3_v2.re = c3_t1 + c3_y.re;
      c3_v2.im = c3_y.im;
      break;

     case 3:
      CV_EML_SWITCH(0, 1, 0, 4);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 47);
      c3_s1 = 4.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
      c3_pol2cart(chartInstance, c3_Vdc, 3.1415926535897931, &c3_g_t1, &c3_g_t2);
      c3_t1 = c3_g_t1;
      c3_t2 = c3_g_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
      c3_g_b = c3_t2;
      c3_y.re = c3_g_b * c3_dc0.re;
      c3_y.im = c3_g_b * c3_dc0.im;
      c3_v1.re = c3_t1 + c3_y.re;
      c3_v1.im = c3_y.im;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
      c3_s2 = 5.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
      c3_pol2cart(chartInstance, c3_Vdc, 4.1887902047863905, &c3_h_t1, &c3_h_t2);
      c3_t1 = c3_h_t1;
      c3_t2 = c3_h_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
      c3_h_b = c3_t2;
      c3_y.re = c3_h_b * c3_dc0.re;
      c3_y.im = c3_h_b * c3_dc0.im;
      c3_v2.re = c3_t1 + c3_y.re;
      c3_v2.im = c3_y.im;
      break;

     case 4:
      CV_EML_SWITCH(0, 1, 0, 5);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
      c3_s1 = 5.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
      c3_pol2cart(chartInstance, c3_Vdc, 4.1887902047863905, &c3_i_t1, &c3_i_t2);
      c3_t1 = c3_i_t1;
      c3_t2 = c3_i_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
      c3_i_b = c3_t2;
      c3_y.re = c3_i_b * c3_dc0.re;
      c3_y.im = c3_i_b * c3_dc0.im;
      c3_v1.re = c3_t1 + c3_y.re;
      c3_v1.im = c3_y.im;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 60);
      c3_s2 = 6.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 61);
      c3_pol2cart(chartInstance, c3_Vdc, 5.2359877559829888, &c3_j_t1, &c3_j_t2);
      c3_t1 = c3_j_t1;
      c3_t2 = c3_j_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
      c3_j_b = c3_t2;
      c3_y.re = c3_j_b * c3_dc0.re;
      c3_y.im = c3_j_b * c3_dc0.im;
      c3_v2.re = c3_t1 + c3_y.re;
      c3_v2.im = c3_y.im;
      break;

     case 5:
      CV_EML_SWITCH(0, 1, 0, 6);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
      c3_s1 = 6.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
      c3_pol2cart(chartInstance, c3_Vdc, 5.2359877559829888, &c3_k_t1, &c3_k_t2);
      c3_t1 = c3_k_t1;
      c3_t2 = c3_k_t2;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
      c3_k_b = c3_t2;
      c3_y.re = c3_k_b * c3_dc0.re;
      c3_y.im = c3_k_b * c3_dc0.im;
      c3_v1.re = c3_t1 + c3_y.re;
      c3_v1.im = c3_y.im;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 68);
      c3_s2 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 69);
      c3_v2.re = c3_Vdc;
      c3_v2.im = 0.0;
      break;

     default:
      CV_EML_SWITCH(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 71);
      c3_s1 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
      c3_s2 = 0.0;
      break;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 78);
    c3_a = c3_v2.im;
    c3_l_b = c3_Vb;
    c3_c_y = c3_a * c3_l_b;
    c3_b_A = c3_c_y;
    c3_B = c3_v2.re;
    c3_e_x = c3_b_A;
    c3_d_y = c3_B;
    c3_f_x = c3_e_x;
    c3_e_y = c3_d_y;
    c3_f_y = c3_f_x / c3_e_y;
    c3_num = (c3_Va - c3_f_y) - c3_v1.im;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 79);
    c3_c_A = c3_v2.im;
    c3_b_B = c3_v2.re;
    c3_g_x = c3_c_A;
    c3_g_y = c3_b_B;
    c3_h_x = c3_g_x;
    c3_h_y = c3_g_y;
    c3_i_y = c3_h_x / c3_h_y;
    c3_den = c3_v1.re - c3_i_y;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
    c3_d_A = c3_num;
    c3_c_B = c3_den;
    c3_i_x = c3_d_A;
    c3_j_y = c3_c_B;
    c3_j_x = c3_i_x;
    c3_k_y = c3_j_y;
    c3_xint = c3_j_x / c3_k_y;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 82);
    c3_e_A = c3_v1.im;
    c3_d_B = c3_v1.re;
    c3_k_x = c3_e_A;
    c3_l_y = c3_d_B;
    c3_l_x = c3_k_x;
    c3_m_y = c3_l_y;
    c3_n_y = c3_l_x / c3_m_y;
    c3_b_a = c3_n_y;
    c3_m_b = c3_xint;
    c3_yint = c3_b_a * c3_m_b;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
    c3_f_A = c3_mpower(chartInstance, c3_xint) + c3_mpower(chartInstance,
      c3_yint);
    c3_b_sqrt(chartInstance, &c3_f_A);
    c3_e_B = c3_Vdc;
    c3_m_x = c3_f_A;
    c3_o_y = c3_e_B;
    c3_n_x = c3_m_x;
    c3_p_y = c3_o_y;
    c3_dc1 = c3_n_x / c3_p_y;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 90);
    c3_g_A = c3_mpower(chartInstance, c3_xint - c3_Va) + c3_mpower(chartInstance,
      c3_yint - c3_Vb);
    c3_b_sqrt(chartInstance, &c3_g_A);
    c3_f_B = c3_Vdc;
    c3_o_x = c3_g_A;
    c3_q_y = c3_f_B;
    c3_p_x = c3_o_x;
    c3_r_y = c3_q_y;
    c3_dc2 = c3_p_x / c3_r_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 95);
    c3_s2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
    c3_dc2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 97);
    c3_h_A = c3_theta;
    c3_q_x = c3_h_A;
    c3_r_x = c3_q_x;
    c3_s_y = c3_r_x / 6.0;
    c3_s_x = c3_s_y;
    c3_ang = c3_s_x;
    c3_t_x = c3_ang;
    c3_ang = c3_t_x;
    c3_ang = muDoubleScalarFloor(c3_ang);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 98);
    c3_i_A = c3_mpower(chartInstance, c3_Va) + c3_mpower(chartInstance, c3_Vb);
    c3_b_sqrt(chartInstance, &c3_i_A);
    c3_g_B = c3_Vdc;
    c3_u_x = c3_i_A;
    c3_t_y = c3_g_B;
    c3_v_x = c3_u_x;
    c3_u_y = c3_t_y;
    c3_dc1 = c3_v_x / c3_u_y;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 100);
    switch ((int32_T)_SFD_INTEGER_CHECK("ang", c3_ang)) {
     case 0:
      CV_EML_SWITCH(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 102);
      if (CV_EML_IF(0, 1, 1, c3_DTorque >= 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 103);
        c3_s1 = 2.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 105);
        c3_s1 = 6.0;
      }
      break;

     case 1:
      CV_EML_SWITCH(0, 1, 1, 2);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 109);
      if (CV_EML_IF(0, 1, 2, c3_DTorque >= 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 110);
        c3_s1 = 3.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 112);
        c3_s1 = 1.0;
      }
      break;

     case 2:
      CV_EML_SWITCH(0, 1, 1, 3);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 116);
      if (CV_EML_IF(0, 1, 3, c3_DTorque >= 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 117);
        c3_s1 = 4.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 119);
        c3_s1 = 2.0;
      }
      break;

     case 3:
      CV_EML_SWITCH(0, 1, 1, 4);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 122);
      if (CV_EML_IF(0, 1, 4, c3_DTorque >= 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 123);
        c3_s1 = 5.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 125);
        c3_s1 = 3.0;
      }
      break;

     case 4:
      CV_EML_SWITCH(0, 1, 1, 5);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 128U);
      if (CV_EML_IF(0, 1, 5, c3_DTorque >= 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 129U);
        c3_s1 = 6.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 131U);
        c3_s1 = 4.0;
      }
      break;

     case 5:
      CV_EML_SWITCH(0, 1, 1, 6);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 134U);
      if (CV_EML_IF(0, 1, 6, c3_DTorque >= 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 135U);
        c3_s1 = 1.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 137U);
        c3_s1 = 5.0;
      }
      break;

     default:
      CV_EML_SWITCH(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 140U);
      c3_s1 = 0.0;
      break;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -140);
  sf_debug_symbol_scope_pop();
  *c3_b_s1 = c3_s1;
  *c3_c_dc1 = c3_dc1;
  *c3_b_s2 = c3_s2;
  *c3_b_dc2 = c3_dc2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_motor_control(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_dc2, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dc2), &c3_thisId);
  sf_mex_destroy(&c3_dc2);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_dc2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_dc2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dc2), &c3_thisId);
  sf_mex_destroy(&c3_dc2);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  creal_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(creal_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static creal_T c3_c_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  creal_T c3_y;
  creal_T c3_dc2;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_dc2, 1, 0, 1U, 0, 0U, 0);
  c3_y = c3_dc2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_v2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  creal_T c3_y;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_v2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_v2), &c3_thisId);
  sf_mex_destroy(&c3_v2);
  *(creal_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_positiveInput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_positiveInput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_positiveInput),
    &c3_thisId);
  sf_mex_destroy(&c3_positiveInput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_motor_control_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[42];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i0;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 42), FALSE);
  for (c3_i0 = 0; c3_i0 < 42; c3_i0++) {
    c3_r0 = &c3_info[c3_i0];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i0);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[42])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289541292U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "atan2";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[1].fileTimeLo = 1286840304U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[2].name = "eml_scalar_eg";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[2].fileTimeLo = 1286840396U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[3].name = "eml_scalexp_alloc";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[3].fileTimeLo = 1286840396U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[4].name = "eml_scalar_atan2";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c3_info[4].fileTimeLo = 1286840320U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "mod";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c3_info[5].fileTimeLo = 1286840344U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c3_info[6].name = "eml_scalar_eg";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[6].fileTimeLo = 1286840396U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c3_info[7].name = "eml_scalexp_alloc";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[7].fileTimeLo = 1286840396U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c3_info[8].name = "eml_scalar_mod";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c3_info[8].fileTimeLo = 1307672838U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c3_info[9].name = "eml_scalar_eg";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[9].fileTimeLo = 1286840396U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c3_info[10].name = "eml_scalar_floor";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[10].fileTimeLo = 1286840326U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c3_info[11].name = "eml_scalar_round";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c3_info[11].fileTimeLo = 1307672838U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c3_info[12].name = "eml_scalar_abs";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[12].fileTimeLo = 1286840312U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c3_info[13].name = "eps";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[13].fileTimeLo = 1307672840U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[14].name = "eml_is_float_class";
  c3_info[14].dominantType = "char";
  c3_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[14].fileTimeLo = 1286840382U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[15].name = "eml_eps";
  c3_info[15].dominantType = "char";
  c3_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[15].fileTimeLo = 1307672840U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c3_info[16].name = "eml_float_model";
  c3_info[16].dominantType = "char";
  c3_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c3_info[16].fileTimeLo = 1307672842U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c3_info[17].name = "mtimes";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[17].fileTimeLo = 1289541292U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context = "";
  c3_info[18].name = "eml_li_find";
  c3_info[18].dominantType = "";
  c3_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c3_info[18].fileTimeLo = 1286840386U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c3_info[19].name = "eml_index_class";
  c3_info[19].dominantType = "";
  c3_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[19].fileTimeLo = 1286840378U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c3_info[20].name = "eml_index_class";
  c3_info[20].dominantType = "";
  c3_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[20].fileTimeLo = 1286840378U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c3_info[21].name = "eml_index_plus";
  c3_info[21].dominantType = "int32";
  c3_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[21].fileTimeLo = 1286840378U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[22].name = "eml_index_class";
  c3_info[22].dominantType = "";
  c3_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[22].fileTimeLo = 1286840378U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c3_info[23].name = "eml_index_plus";
  c3_info[23].dominantType = "int32";
  c3_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[23].fileTimeLo = 1286840378U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context = "";
  c3_info[24].name = "mrdivide";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[24].fileTimeLo = 1325145738U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 1319751566U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[25].name = "rdivide";
  c3_info[25].dominantType = "double";
  c3_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[25].fileTimeLo = 1286840444U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[26].name = "eml_div";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[26].fileTimeLo = 1313369410U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
  c3_info[27].context = "";
  c3_info[27].name = "floor";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[27].fileTimeLo = 1286840342U;
  c3_info[27].fileTimeHi = 0U;
  c3_info[27].mFileTimeLo = 0U;
  c3_info[27].mFileTimeHi = 0U;
  c3_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[28].name = "eml_scalar_floor";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[28].fileTimeLo = 1286840326U;
  c3_info[28].fileTimeHi = 0U;
  c3_info[28].mFileTimeLo = 0U;
  c3_info[28].mFileTimeHi = 0U;
  c3_info[29].context = "";
  c3_info[29].name = "pol2cart";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c3_info[29].fileTimeLo = 1286840454U;
  c3_info[29].fileTimeHi = 0U;
  c3_info[29].mFileTimeLo = 0U;
  c3_info[29].mFileTimeHi = 0U;
  c3_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c3_info[30].name = "cos";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[30].fileTimeLo = 1286840306U;
  c3_info[30].fileTimeHi = 0U;
  c3_info[30].mFileTimeLo = 0U;
  c3_info[30].mFileTimeHi = 0U;
  c3_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[31].name = "eml_scalar_cos";
  c3_info[31].dominantType = "double";
  c3_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[31].fileTimeLo = 1286840322U;
  c3_info[31].fileTimeHi = 0U;
  c3_info[31].mFileTimeLo = 0U;
  c3_info[31].mFileTimeHi = 0U;
  c3_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c3_info[32].name = "sin";
  c3_info[32].dominantType = "double";
  c3_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[32].fileTimeLo = 1286840350U;
  c3_info[32].fileTimeHi = 0U;
  c3_info[32].mFileTimeLo = 0U;
  c3_info[32].mFileTimeHi = 0U;
  c3_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[33].name = "eml_scalar_sin";
  c3_info[33].dominantType = "double";
  c3_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[33].fileTimeLo = 1286840336U;
  c3_info[33].fileTimeHi = 0U;
  c3_info[33].mFileTimeLo = 0U;
  c3_info[33].mFileTimeHi = 0U;
  c3_info[34].context = "";
  c3_info[34].name = "mpower";
  c3_info[34].dominantType = "double";
  c3_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[34].fileTimeLo = 1286840442U;
  c3_info[34].fileTimeHi = 0U;
  c3_info[34].mFileTimeLo = 0U;
  c3_info[34].mFileTimeHi = 0U;
  c3_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[35].name = "power";
  c3_info[35].dominantType = "double";
  c3_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[35].fileTimeLo = 1307672840U;
  c3_info[35].fileTimeHi = 0U;
  c3_info[35].mFileTimeLo = 0U;
  c3_info[35].mFileTimeHi = 0U;
  c3_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[36].name = "eml_scalar_eg";
  c3_info[36].dominantType = "double";
  c3_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[36].fileTimeLo = 1286840396U;
  c3_info[36].fileTimeHi = 0U;
  c3_info[36].mFileTimeLo = 0U;
  c3_info[36].mFileTimeHi = 0U;
  c3_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[37].name = "eml_scalexp_alloc";
  c3_info[37].dominantType = "double";
  c3_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[37].fileTimeLo = 1286840396U;
  c3_info[37].fileTimeHi = 0U;
  c3_info[37].mFileTimeLo = 0U;
  c3_info[37].mFileTimeHi = 0U;
  c3_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[38].name = "eml_scalar_floor";
  c3_info[38].dominantType = "double";
  c3_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[38].fileTimeLo = 1286840326U;
  c3_info[38].fileTimeHi = 0U;
  c3_info[38].mFileTimeLo = 0U;
  c3_info[38].mFileTimeHi = 0U;
  c3_info[39].context = "";
  c3_info[39].name = "sqrt";
  c3_info[39].dominantType = "double";
  c3_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[39].fileTimeLo = 1286840352U;
  c3_info[39].fileTimeHi = 0U;
  c3_info[39].mFileTimeLo = 0U;
  c3_info[39].mFileTimeHi = 0U;
  c3_info[40].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[40].name = "eml_error";
  c3_info[40].dominantType = "char";
  c3_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[40].fileTimeLo = 1305339600U;
  c3_info[40].fileTimeHi = 0U;
  c3_info[40].mFileTimeLo = 0U;
  c3_info[40].mFileTimeHi = 0U;
  c3_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[41].name = "eml_scalar_sqrt";
  c3_info[41].dominantType = "double";
  c3_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[41].fileTimeLo = 1286840338U;
  c3_info[41].fileTimeHi = 0U;
  c3_info[41].mFileTimeLo = 0U;
  c3_info[41].mFileTimeHi = 0U;
}

static real_T c3_angle(SFc3_motor_controlInstanceStruct *chartInstance, creal_T
  c3_h)
{
  real_T c3_p;
  uint32_T c3_debug_family_var_map[4];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  real_T c3_y;
  real_T c3_x;
  real_T c3_b_y;
  real_T c3_b_x;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_h, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_p, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 179U);
  c3_y = c3_h.im;
  c3_x = c3_h.re;
  c3_b_y = c3_y;
  c3_b_x = c3_x;
  c3_p = muDoubleScalarAtan2(c3_b_y, c3_b_x);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -179);
  sf_debug_symbol_scope_pop();
  return c3_p;
}

static real_T c3_wrapTo2Pi(SFc3_motor_controlInstanceStruct *chartInstance,
  real_T c3_lambda)
{
  real_T c3_b_lambda;
  uint32_T c3_debug_family_var_map[4];
  boolean_T c3_positiveInput;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  real_T c3_x;
  real_T c3_xk;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_y;
  real_T c3_g_x;
  real_T c3_b_y;
  real_T c3_b;
  real_T c3_c_y;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_dv0[1];
  boolean_T c3_b1;
  boolean_T c3_b_positiveInput;
  boolean_T c3_j_x;
  boolean_T c3_k_x;
  int32_T c3_k;
  int32_T c3_tmp_sizes[2];
  int32_T c3_iv0[2];
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_loop_ub;
  int32_T c3_i3;
  int32_T c3_tmp_data[1];
  int32_T c3_i4;
  int32_T c3_b_tmp_sizes[2];
  int32_T c3_b_tmp_data[1];
  int32_T c3_b_loop_ub;
  int32_T c3_i5;
  sf_debug_symbol_scope_push_eml(0U, 4U, 5U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_positiveInput, 0U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_lambda, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b_lambda, MAX_uint32_T,
    c3_sf_marshallOut, c3_sf_marshallIn);
  c3_b_lambda = c3_lambda;
  sf_debug_symbol_switch(3U, 4U);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 161U);
  c3_positiveInput = (c3_b_lambda > 0.0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 162U);
  c3_x = c3_b_lambda;
  c3_xk = c3_x;
  c3_b_x = c3_xk;
  c3_c_x = c3_b_x;
  c3_b_lambda = c3_c_x / 6.2831853071795862;
  c3_d_x = c3_b_lambda;
  c3_e_x = c3_d_x;
  c3_e_x = muDoubleScalarRound(c3_e_x);
  c3_f_x = c3_b_lambda - c3_e_x;
  c3_y = muDoubleScalarAbs(c3_f_x);
  c3_g_x = c3_b_lambda;
  c3_b_y = muDoubleScalarAbs(c3_g_x);
  c3_b = c3_b_y;
  c3_c_y = 2.2204460492503131E-16 * c3_b;
  if (c3_y <= c3_c_y) {
    c3_b_lambda = 0.0;
  } else {
    c3_h_x = c3_b_lambda;
    c3_i_x = c3_h_x;
    c3_i_x = muDoubleScalarFloor(c3_i_x);
    c3_b_lambda = (c3_b_lambda - c3_i_x) * 6.2831853071795862;
  }

  sf_debug_symbol_switch(3U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 163U);
  c3_dv0[0] = c3_b_lambda;
  c3_b1 = (c3_b_lambda == 0.0);
  c3_b_positiveInput = c3_positiveInput;
  c3_j_x = (c3_b1 && c3_b_positiveInput);
  c3_k_x = c3_j_x;
  c3_k = 0;
  if (c3_k_x) {
    c3_k = 1;
  }

  c3_tmp_sizes[0] = 1;
  c3_iv0[0] = 1;
  c3_iv0[1] = c3_k;
  c3_tmp_sizes[1] = c3_iv0[1];
  c3_i1 = c3_tmp_sizes[0];
  c3_i2 = c3_tmp_sizes[1];
  c3_loop_ub = c3_k - 1;
  for (c3_i3 = 0; c3_i3 <= c3_loop_ub; c3_i3++) {
    c3_tmp_data[c3_i3] = 0;
  }

  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    c3_b_tmp_sizes[c3_i4] = c3_tmp_sizes[c3_i4];
  }

  if (c3_j_x) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c3_b_tmp_sizes[1], 1, 0);
    c3_b_tmp_data[0] = 1;
  }

  c3_b_loop_ub = c3_b_tmp_sizes[0] * c3_b_tmp_sizes[1] - 1;
  for (c3_i5 = 0; c3_i5 <= c3_b_loop_ub; c3_i5++) {
    c3_dv0[c3_b_tmp_data[c3_i5] - 1] = 6.2831853071795862;
  }

  c3_b_lambda = c3_dv0[0];
  sf_debug_symbol_switch(3U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -163);
  sf_debug_symbol_scope_pop();
  return c3_b_lambda;
}

static void c3_pol2cart(SFc3_motor_controlInstanceStruct *chartInstance, real_T
  c3_th, real_T c3_r, real_T *c3_x, real_T *c3_y)
{
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  c3_b_x = c3_th;
  c3_c_x = c3_b_x;
  c3_c_x = muDoubleScalarCos(c3_c_x);
  *c3_x = c3_r * c3_c_x;
  c3_d_x = c3_th;
  c3_e_x = c3_d_x;
  c3_e_x = muDoubleScalarSin(c3_e_x);
  *c3_y = c3_r * c3_e_x;
}

static real_T c3_mpower(SFc3_motor_controlInstanceStruct *chartInstance, real_T
  c3_a)
{
  real_T c3_b_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_ak = c3_b_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static real_T c3_sqrt(SFc3_motor_controlInstanceStruct *chartInstance, real_T
                      c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  c3_b_sqrt(chartInstance, &c3_b_x);
  return c3_b_x;
}

static void c3_eml_error(SFc3_motor_controlInstanceStruct *chartInstance)
{
  int32_T c3_i6;
  static char_T c3_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i6 = 0; c3_i6 < 30; c3_i6++) {
    c3_u[c3_i6] = c3_varargin_1[c3_i6];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i7;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i7, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i7;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_motor_control, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_motor_control), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_motor_control);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_motor_controlInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sqrt(SFc3_motor_controlInstanceStruct *chartInstance, real_T
                      *c3_x)
{
  if (*c3_x < 0.0) {
    c3_eml_error(chartInstance);
  }

  *c3_x = muDoubleScalarSqrt(*c3_x);
}

static void init_dsm_address_info(SFc3_motor_controlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_motor_control_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4109677018U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(205815469U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1454287889U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4055048615U);
}

mxArray *sf_c3_motor_control_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("CeIajNKHkm4A9la3zWq8nG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c3_motor_control(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[9],T\"dc1\",},{M[1],M[10],T\"dc2\",},{M[1],M[5],T\"s1\",},{M[1],M[7],T\"s2\",},{M[8],M[0],T\"is_active_c3_motor_control\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_motor_control_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_motor_controlInstanceStruct *chartInstance;
    chartInstance = (SFc3_motor_controlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_motor_controlMachineNumber_,
           3,
           1,
           1,
           10,
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
          init_script_number_translation(_motor_controlMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_motor_controlMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_motor_controlMachineNumber_,
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
          _SFD_SET_DATA_PROPS(7,1,1,0,"tracking");
          _SFD_SET_DATA_PROPS(8,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(9,1,1,0,"DTorque");
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
        _SFD_CV_INIT_EML(0,1,3,7,0,2,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3432);
        _SFD_CV_INIT_EML_FCN(0,1,"wrapTo2Pi",3434,-1,4027);
        _SFD_CV_INIT_EML_FCN(0,2,"angle",4029,-1,4385);
        _SFD_CV_INIT_EML_IF(0,1,0,94,111,2373,3425);
        _SFD_CV_INIT_EML_IF(0,1,1,2629,2645,2682,2726);
        _SFD_CV_INIT_EML_IF(0,1,2,2767,2783,2820,2864);
        _SFD_CV_INIT_EML_IF(0,1,3,2905,2921,2958,3002);
        _SFD_CV_INIT_EML_IF(0,1,4,3030,3046,3083,3127);
        _SFD_CV_INIT_EML_IF(0,1,5,3155,3171,3208,3252);
        _SFD_CV_INIT_EML_IF(0,1,6,3280,3296,3333,3377);

        {
          static int caseStart[] = { 1796, 597, 770, 993, 1201, 1409, 1634 };

          static int caseExprEnd[] = { 1805, 603, 776, 999, 1207, 1415, 1640 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,577,589,1853,7,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int caseStart[] = { 3386, 2610, 2748, 2886, 3011, 3136, 3261 };

          static int caseExprEnd[] = { 3395, 2616, 2754, 2892, 3017, 3142, 3267
          };

          _SFD_CV_INIT_EML_SWITCH(0,1,1,2590,2601,3421,7,&(caseStart[0]),
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_Va;
          real_T *c3_s1;
          real_T *c3_dc1;
          real_T *c3_Vb;
          real_T *c3_s2;
          real_T *c3_Vdc;
          real_T *c3_dc2;
          real_T *c3_tracking;
          real_T *c3_theta;
          real_T *c3_DTorque;
          c3_DTorque = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_tracking = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Va);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_s1);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_dc1);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_Vb);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_s2);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Vdc);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_dc2);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_tracking);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_theta);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_DTorque);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_motor_controlMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "bKvNSZkxXIqpTjfsXe6zzB";
}

static void sf_opaque_initialize_c3_motor_control(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_motor_controlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_motor_control((SFc3_motor_controlInstanceStruct*)
    chartInstanceVar);
  initialize_c3_motor_control((SFc3_motor_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_motor_control(void *chartInstanceVar)
{
  enable_c3_motor_control((SFc3_motor_controlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_motor_control(void *chartInstanceVar)
{
  disable_c3_motor_control((SFc3_motor_controlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_motor_control(void *chartInstanceVar)
{
  sf_c3_motor_control((SFc3_motor_controlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_motor_control(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_motor_control
    ((SFc3_motor_controlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_motor_control();/* state var info */
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

extern void sf_internal_set_sim_state_c3_motor_control(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_motor_control();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_motor_control((SFc3_motor_controlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_motor_control(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_motor_control(S);
}

static void sf_opaque_set_sim_state_c3_motor_control(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_motor_control(S, st);
}

static void sf_opaque_terminate_c3_motor_control(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_motor_controlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_motor_control((SFc3_motor_controlInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_motor_control_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_motor_control((SFc3_motor_controlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_motor_control(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_motor_control((SFc3_motor_controlInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_motor_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_motor_control_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1062005247U));
  ssSetChecksum1(S,(663131768U));
  ssSetChecksum2(S,(3878096744U));
  ssSetChecksum3(S,(2447609753U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_motor_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_motor_control(SimStruct *S)
{
  SFc3_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_controlInstanceStruct *)malloc(sizeof
    (SFc3_motor_controlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_motor_controlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_motor_control;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_motor_control;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_motor_control;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_motor_control;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_motor_control;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_motor_control;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_motor_control;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_motor_control;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_motor_control;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_motor_control;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_motor_control;
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

void c3_motor_control_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_motor_control(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_motor_control(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_motor_control(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_motor_control_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
