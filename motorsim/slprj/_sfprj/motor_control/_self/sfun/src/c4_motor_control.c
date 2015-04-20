/* Include files */

#include "blascompat32.h"
#include "motor_control_sfun.h"
#include "c4_motor_control.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "motor_control_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[17] = { "Tsamp", "Tswitch", "output",
  "gates", "nargin", "nargout", "s1", "dc1", "s2", "dc2", "gAh", "gAl", "gBh",
  "gBl", "gCh", "gCl", "k" };

/* Function Declarations */
static void initialize_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance);
static void initialize_params_c4_motor_control(SFc4_motor_controlInstanceStruct *
  chartInstance);
static void enable_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance);
static void disable_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_motor_control
  (SFc4_motor_controlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_motor_control
  (SFc4_motor_controlInstanceStruct *chartInstance);
static void set_sim_state_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance);
static void sf_c4_motor_control(SFc4_motor_controlInstanceStruct *chartInstance);
static void c4_chartstep_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance);
static void initSimStructsc4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_b_k, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_gCl, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[6]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_eml_scalar_eg(SFc4_motor_controlInstanceStruct *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_g_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_motor_control, const char_T
  *c4_identifier);
static uint8_T c4_h_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_motor_controlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_k_not_empty = FALSE;
  chartInstance->c4_is_active_c4_motor_control = 0U;
}

static void initialize_params_c4_motor_control(SFc4_motor_controlInstanceStruct *
  chartInstance)
{
}

static void enable_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_motor_control
  (SFc4_motor_controlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_motor_control
  (SFc4_motor_controlInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T c4_f_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  uint8_T c4_h_hoistedGlobal;
  uint8_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  real_T *c4_gAh;
  real_T *c4_gAl;
  real_T *c4_gBh;
  real_T *c4_gBl;
  real_T *c4_gCh;
  real_T *c4_gCl;
  c4_gCl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_gCh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_gBl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_gBh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_gAl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gAh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(8), FALSE);
  c4_hoistedGlobal = *c4_gAh;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_gAl;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_gBh;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_gBl;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *c4_gCh;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = *c4_gCl;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = chartInstance->c4_k;
  c4_g_u = c4_g_hoistedGlobal;
  c4_h_y = NULL;
  if (!chartInstance->c4_k_not_empty) {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_h_hoistedGlobal = chartInstance->c4_is_active_c4_motor_control;
  c4_h_u = c4_h_hoistedGlobal;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_gAh;
  real_T *c4_gAl;
  real_T *c4_gBh;
  real_T *c4_gBl;
  real_T *c4_gCh;
  real_T *c4_gCl;
  c4_gCl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_gCh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_gBl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_gBh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_gAl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gAh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_gAh = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    0)), "gAh");
  *c4_gAl = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    1)), "gAl");
  *c4_gBh = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    2)), "gBh");
  *c4_gBl = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    3)), "gBl");
  *c4_gCh = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    4)), "gCh");
  *c4_gCl = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    5)), "gCl");
  chartInstance->c4_k = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "k");
  chartInstance->c4_is_active_c4_motor_control = c4_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
     "is_active_c4_motor_control");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_motor_control(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
}

static void sf_c4_motor_control(SFc4_motor_controlInstanceStruct *chartInstance)
{
  real_T *c4_s1;
  real_T *c4_gAh;
  real_T *c4_dc1;
  real_T *c4_s2;
  real_T *c4_dc2;
  real_T *c4_gAl;
  real_T *c4_gBh;
  real_T *c4_gBl;
  real_T *c4_gCh;
  real_T *c4_gCl;
  c4_gCl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_gCh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_gBl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_gBh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_gAl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_gAh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_s1, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gAh, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_dc1, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_s2, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_dc2, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_gAl, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_gBh, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_gBl, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_gCh, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_gCl, 9U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_motor_control(chartInstance);
  sf_debug_check_for_state_inconsistency(_motor_controlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_s1;
  real_T c4_dc1;
  real_T c4_s2;
  real_T c4_dc2;
  uint32_T c4_debug_family_var_map[17];
  real_T c4_Tsamp;
  real_T c4_Tswitch;
  real_T c4_output;
  real_T c4_gates[6];
  real_T c4_nargin = 4.0;
  real_T c4_nargout = 6.0;
  real_T c4_gAh;
  real_T c4_gAl;
  real_T c4_gBh;
  real_T c4_gBl;
  real_T c4_gCh;
  real_T c4_gCl;
  real_T c4_e_hoistedGlobal;
  real_T c4_b;
  real_T c4_y;
  real_T c4_f_hoistedGlobal;
  real_T c4_b_b;
  real_T c4_b_y;
  int32_T c4_i0;
  static real_T c4_dv0[6] = { 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };

  int32_T c4_i1;
  static real_T c4_dv1[6] = { 1.0, 0.0, 0.0, 1.0, 0.0, 1.0 };

  int32_T c4_i2;
  static real_T c4_dv2[6] = { 1.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  int32_T c4_i3;
  static real_T c4_dv3[6] = { 0.0, 1.0, 1.0, 0.0, 0.0, 1.0 };

  int32_T c4_i4;
  static real_T c4_dv4[6] = { 0.0, 1.0, 1.0, 0.0, 1.0, 0.0 };

  int32_T c4_i5;
  static real_T c4_dv5[6] = { 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 };

  int32_T c4_i6;
  static real_T c4_dv6[6] = { 1.0, 0.0, 0.0, 1.0, 1.0, 0.0 };

  int32_T c4_i7;
  real_T *c4_b_s1;
  real_T *c4_b_dc1;
  real_T *c4_b_s2;
  real_T *c4_b_dc2;
  real_T *c4_b_gAh;
  real_T *c4_b_gAl;
  real_T *c4_b_gBh;
  real_T *c4_b_gBl;
  real_T *c4_b_gCh;
  real_T *c4_b_gCl;
  c4_b_gCl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_b_gCh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_b_gBl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_gBh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_gAl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_gAh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_s1;
  c4_b_hoistedGlobal = *c4_b_dc1;
  c4_c_hoistedGlobal = *c4_b_s2;
  c4_d_hoistedGlobal = *c4_b_dc2;
  c4_s1 = c4_hoistedGlobal;
  c4_dc1 = c4_b_hoistedGlobal;
  c4_s2 = c4_c_hoistedGlobal;
  c4_dc2 = c4_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_Tsamp, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_Tswitch, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_output, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_gates, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_s1, 6U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_dc1, 7U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_s2, 8U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_dc2, 9U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_gAh, 10U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_gAl, 11U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_gBh, 12U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_gBl, 13U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_gCh, 14U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_gCl, 15U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c4_k, 16U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_eml_scalar_eg(chartInstance);
  c4_Tsamp = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_eml_scalar_eg(chartInstance);
  c4_Tswitch = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c4_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
    chartInstance->c4_k = 1.0;
    chartInstance->c4_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  if (CV_EML_IF(0, 1, 1, chartInstance->c4_k > 100.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
    chartInstance->c4_k = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_e_hoistedGlobal = chartInstance->c4_k;
  c4_b = c4_dc1;
  c4_y = 100.0 * c4_b;
  if (CV_EML_IF(0, 1, 2, c4_e_hoistedGlobal < c4_y)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
    c4_output = c4_s1;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
    c4_f_hoistedGlobal = chartInstance->c4_k;
    c4_b_b = c4_dc2;
    c4_b_y = 100.0 * c4_b_b;
    if (CV_EML_IF(0, 1, 3, c4_f_hoistedGlobal > 100.0 - c4_b_y)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
      c4_output = c4_s2;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
      c4_output = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
  switch ((int32_T)_SFD_INTEGER_CHECK("output", c4_output)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
    for (c4_i0 = 0; c4_i0 < 6; c4_i0++) {
      c4_gates[c4_i0] = c4_dv0[c4_i0];
    }
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
    for (c4_i1 = 0; c4_i1 < 6; c4_i1++) {
      c4_gates[c4_i1] = c4_dv1[c4_i1];
    }
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
    for (c4_i2 = 0; c4_i2 < 6; c4_i2++) {
      c4_gates[c4_i2] = c4_dv2[c4_i2];
    }
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
    for (c4_i3 = 0; c4_i3 < 6; c4_i3++) {
      c4_gates[c4_i3] = c4_dv3[c4_i3];
    }
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
    for (c4_i4 = 0; c4_i4 < 6; c4_i4++) {
      c4_gates[c4_i4] = c4_dv4[c4_i4];
    }
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
    for (c4_i5 = 0; c4_i5 < 6; c4_i5++) {
      c4_gates[c4_i5] = c4_dv5[c4_i5];
    }
    break;

   case 6:
    CV_EML_SWITCH(0, 1, 0, 7);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 50);
    for (c4_i6 = 0; c4_i6 < 6; c4_i6++) {
      c4_gates[c4_i6] = c4_dv6[c4_i6];
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 53);
    for (c4_i7 = 0; c4_i7 < 6; c4_i7++) {
      c4_gates[c4_i7] = 0.0;
    }
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 59);
  c4_gAh = c4_gates[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 60);
  c4_gAl = c4_gates[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 61);
  c4_gBh = c4_gates[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 62);
  c4_gBl = c4_gates[3];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 63);
  c4_gCh = c4_gates[4];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 64);
  c4_gCl = c4_gates[5];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -64);
  sf_debug_symbol_scope_pop();
  *c4_b_gAh = c4_gAh;
  *c4_b_gAl = c4_gAl;
  *c4_b_gBh = c4_gBh;
  *c4_b_gBl = c4_gBl;
  *c4_b_gCh = c4_gCh;
  *c4_b_gCl = c4_gCl;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_motor_control(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_k_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_b_k, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_k), &c4_thisId);
  sf_mex_destroy(&c4_b_k);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_k_not_empty = FALSE;
  } else {
    chartInstance->c4_k_not_empty = TRUE;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_k;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_b_k = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_k), &c4_thisId);
  sf_mex_destroy(&c4_b_k);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_gCl, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_gCl), &c4_thisId);
  sf_mex_destroy(&c4_gCl);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_gCl;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_gCl = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_gCl), &c4_thisId);
  sf_mex_destroy(&c4_gCl);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i8;
  real_T c4_b_inData[6];
  int32_T c4_i9;
  real_T c4_u[6];
  const mxArray *c4_y = NULL;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i8 = 0; c4_i8 < 6; c4_i8++) {
    c4_b_inData[c4_i8] = (*(real_T (*)[6])c4_inData)[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 6; c4_i9++) {
    c4_u[c4_i9] = c4_b_inData[c4_i9];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[6])
{
  real_T c4_dv7[6];
  int32_T c4_i10;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv7, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c4_i10 = 0; c4_i10 < 6; c4_i10++) {
    c4_y[c4_i10] = c4_dv7[c4_i10];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_gates;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[6];
  int32_T c4_i11;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_gates = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_gates), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_gates);
  for (c4_i11 = 0; c4_i11 < 6; c4_i11++) {
    (*(real_T (*)[6])c4_outData)[c4_i11] = c4_y[c4_i11];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_motor_control_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[6];
  c4_ResolvedFunctionInfo (*c4_b_info)[6];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i12;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[6])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mpower";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c4_b_info)[0].fileTimeLo = 1286840442U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c4_b_info)[1].name = "power";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c4_b_info)[1].fileTimeLo = 1307672840U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c4_b_info)[2].name = "eml_scalar_eg";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c4_b_info)[2].fileTimeLo = 1286840396U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c4_b_info)[3].name = "eml_scalexp_alloc";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c4_b_info)[3].fileTimeLo = 1286840396U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c4_b_info)[4].name = "eml_scalar_floor";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c4_b_info)[4].fileTimeLo = 1286840326U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context = "";
  (*c4_b_info)[5].name = "mtimes";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[5].fileTimeLo = 1289541292U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 0U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c4_i12 = 0; c4_i12 < 6; c4_i12++) {
    c4_r0 = &c4_info[c4_i12];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i12);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i12);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_eml_scalar_eg(SFc4_motor_controlInstanceStruct *chartInstance)
{
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i13;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i13, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i13;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_motor_control, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_motor_control), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_motor_control);
  return c4_y;
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_motor_controlInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_motor_controlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_motor_control_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1420877996U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2671503029U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3264261171U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1495128902U);
}

mxArray *sf_c4_motor_control_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LqKKKGrYThPZ7hgDcmpU0B");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_motor_control(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"gAh\",},{M[1],M[9],T\"gAl\",},{M[1],M[10],T\"gBh\",},{M[1],M[11],T\"gBl\",},{M[1],M[12],T\"gCh\",},{M[1],M[13],T\"gCl\",},{M[4],M[0],T\"k\",S'l','i','p'{{M1x2[128 129],M[0],}}},{M[8],M[0],T\"is_active_c4_motor_control\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_motor_control_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_motor_controlInstanceStruct *chartInstance;
    chartInstance = (SFc4_motor_controlInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_motor_controlMachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"s1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"gAh");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dc1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"s2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dc2");
          _SFD_SET_DATA_PROPS(5,2,0,1,"gAl");
          _SFD_SET_DATA_PROPS(6,2,0,1,"gBh");
          _SFD_SET_DATA_PROPS(7,2,0,1,"gBl");
          _SFD_SET_DATA_PROPS(8,2,0,1,"gCh");
          _SFD_SET_DATA_PROPS(9,2,0,1,"gCl");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,946);
        _SFD_CV_INIT_EML_IF(0,1,0,132,146,-1,159);
        _SFD_CV_INIT_EML_IF(0,1,1,161,172,-1,185);
        _SFD_CV_INIT_EML_IF(0,1,2,217,230,248,336);
        _SFD_CV_INIT_EML_IF(0,1,3,257,274,300,332);

        {
          static int caseStart[] = { 736, 383, 434, 485, 536, 587, 638, 685 };

          static int caseExprEnd[] = { 745, 389, 440, 491, 542, 593, 644, 691 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,365,379,781,8,&(caseStart[0]),
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
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          real_T *c4_s1;
          real_T *c4_gAh;
          real_T *c4_dc1;
          real_T *c4_s2;
          real_T *c4_dc2;
          real_T *c4_gAl;
          real_T *c4_gBh;
          real_T *c4_gBl;
          real_T *c4_gCh;
          real_T *c4_gCl;
          c4_gCl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c4_gCh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c4_gBl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_gBh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_gAl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_gAh = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_s1);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_gAh);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_dc1);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_s2);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_dc2);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_gAl);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_gBh);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_gBl);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_gCh);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_gCl);
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
  return "1WY7IFokLghWXbdanpgKRE";
}

static void sf_opaque_initialize_c4_motor_control(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_motor_controlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_motor_control((SFc4_motor_controlInstanceStruct*)
    chartInstanceVar);
  initialize_c4_motor_control((SFc4_motor_controlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_motor_control(void *chartInstanceVar)
{
  enable_c4_motor_control((SFc4_motor_controlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_motor_control(void *chartInstanceVar)
{
  disable_c4_motor_control((SFc4_motor_controlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_motor_control(void *chartInstanceVar)
{
  sf_c4_motor_control((SFc4_motor_controlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_motor_control(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_motor_control
    ((SFc4_motor_controlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_motor_control();/* state var info */
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

extern void sf_internal_set_sim_state_c4_motor_control(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_motor_control();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_motor_control((SFc4_motor_controlInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_motor_control(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_motor_control(S);
}

static void sf_opaque_set_sim_state_c4_motor_control(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_motor_control(S, st);
}

static void sf_opaque_terminate_c4_motor_control(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_motor_controlInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_motor_control((SFc4_motor_controlInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_motor_control_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_motor_control((SFc4_motor_controlInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_motor_control(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_motor_control((SFc4_motor_controlInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_motor_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_motor_control_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(326521268U));
  ssSetChecksum1(S,(1965396153U));
  ssSetChecksum2(S,(1515152783U));
  ssSetChecksum3(S,(3640962501U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_motor_control(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_motor_control(SimStruct *S)
{
  SFc4_motor_controlInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_controlInstanceStruct *)malloc(sizeof
    (SFc4_motor_controlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_motor_controlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_motor_control;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_motor_control;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_motor_control;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_motor_control;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_motor_control;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_motor_control;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_motor_control;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_motor_control;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_motor_control;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_motor_control;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_motor_control;
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

void c4_motor_control_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_motor_control(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_motor_control(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_motor_control(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_motor_control_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
