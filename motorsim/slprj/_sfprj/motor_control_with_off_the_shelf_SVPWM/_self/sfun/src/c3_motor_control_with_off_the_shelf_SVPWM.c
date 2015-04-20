/* Include files */

#include "blascompat32.h"
#include "motor_control_with_off_the_shelf_SVPWM_sfun.h"
#include "c3_motor_control_with_off_the_shelf_SVPWM.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "motor_control_with_off_the_shelf_SVPWM_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[13] = { "ang", "d", "pwms", "nargin",
  "nargout", "Valpha", "Vbeta", "Vdc", "Tdes", "Theta", "pwma", "pwmb", "pwmc" };

/* Function Declarations */
static void initialize_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void initialize_params_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void enable_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void disable_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_motor_control_with_off_the_shelf_SVP
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_st);
static void finalize_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void sf_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void initSimStructsc3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_pwmc, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14]);
static real_T c3_mpower
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   real_T c3_a);
static void c3_eml_error
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_b_is_active_c3_motor_control_with_off_the_shelf_SVPWM,
   const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_motor_control_with_off_the_shelf_SVPWM = 0U;
}

static void initialize_params_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static void enable_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_motor_control_with_off_the_shelf_SVP
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
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
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T *c3_pwma;
  real_T *c3_pwmb;
  real_T *c3_pwmc;
  c3_pwmc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_pwmb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_pwma = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(4), FALSE);
  c3_hoistedGlobal = *c3_pwma;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_pwmb;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_pwmc;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal =
    chartInstance->c3_is_active_c3_motor_control_with_off_the_shelf_SVPWM;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_pwma;
  real_T *c3_pwmb;
  real_T *c3_pwmc;
  c3_pwmc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_pwmb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_pwma = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_pwma = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "pwma");
  *c3_pwmb = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    1)), "pwmb");
  *c3_pwmc = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    2)), "pwmc");
  chartInstance->c3_is_active_c3_motor_control_with_off_the_shelf_SVPWM =
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "is_active_c3_motor_control_with_off_the_shelf_SVPWM");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_motor_control_with_off_the_shelf_SVP(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static void sf_c3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_Valpha;
  real_T c3_Vbeta;
  real_T c3_Vdc;
  real_T c3_Tdes;
  real_T c3_Theta;
  uint32_T c3_debug_family_var_map[13];
  real_T c3_ang;
  real_T c3_d;
  real_T c3_pwms[3];
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 3.0;
  real_T c3_pwma;
  real_T c3_pwmb;
  real_T c3_pwmc;
  real_T c3_A;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_b_A;
  real_T c3_B;
  real_T c3_g_x;
  real_T c3_b_y;
  real_T c3_h_x;
  real_T c3_c_y;
  int32_T c3_i0;
  real_T c3_a[3];
  int32_T c3_i1;
  int32_T c3_i2;
  real_T *c3_b_pwmc;
  real_T *c3_b_pwmb;
  real_T *c3_b_pwma;
  real_T *c3_b_Theta;
  real_T *c3_b_Tdes;
  real_T *c3_b_Vdc;
  real_T *c3_b_Vbeta;
  real_T *c3_b_Valpha;
  c3_b_pwmc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_pwmb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_Tdes = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_Vbeta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_pwma = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_Valpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_Valpha, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_pwma, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Vbeta, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Vdc, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Tdes, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Theta, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_b_pwmb, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_b_pwmc, 7U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_Valpha;
  c3_b_hoistedGlobal = *c3_b_Vbeta;
  c3_c_hoistedGlobal = *c3_b_Vdc;
  c3_d_hoistedGlobal = *c3_b_Tdes;
  c3_e_hoistedGlobal = *c3_b_Theta;
  c3_Valpha = c3_hoistedGlobal;
  c3_Vbeta = c3_b_hoistedGlobal;
  c3_Vdc = c3_c_hoistedGlobal;
  c3_Tdes = c3_d_hoistedGlobal;
  c3_Theta = c3_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_ang, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_d, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_pwms, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_Valpha, 5U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Vbeta, 6U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Vdc, 7U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Tdes, 8U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_Theta, 9U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_pwma, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_pwmb, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_pwmc, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_A = c3_Theta;
  c3_x = c3_A;
  c3_b_x = c3_x;
  c3_y = c3_b_x / 1.0471975511965976;
  c3_c_x = c3_y;
  c3_ang = c3_c_x;
  c3_d_x = c3_ang;
  c3_ang = c3_d_x;
  c3_ang = muDoubleScalarFloor(c3_ang);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_e_x = c3_mpower(chartInstance, c3_Valpha) + c3_mpower(chartInstance,
    c3_Vbeta);
  c3_f_x = c3_e_x;
  if (c3_f_x < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_f_x = muDoubleScalarSqrt(c3_f_x);
  c3_b_A = c3_f_x;
  c3_B = c3_Vdc;
  c3_g_x = c3_b_A;
  c3_b_y = c3_B;
  c3_h_x = c3_g_x;
  c3_c_y = c3_b_y;
  c3_d = c3_h_x / c3_c_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_d = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  switch ((int32_T)_SFD_INTEGER_CHECK("ang", c3_ang)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
    if (CV_EML_IF(0, 1, 0, c3_Tdes >= 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
      c3_pwms[0] = c3_d;
      c3_pwms[1] = c3_d;
      c3_pwms[2] = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
      c3_pwms[0] = c3_d;
      c3_pwms[1] = 0.0;
      c3_pwms[2] = 0.0;
    }
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
    if (CV_EML_IF(0, 1, 1, c3_Tdes >= 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
      c3_pwms[0] = 0.0;
      c3_pwms[1] = c3_d;
      c3_pwms[2] = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
      c3_pwms[0] = c3_d;
      c3_pwms[1] = c3_d;
      c3_pwms[2] = 0.0;
    }
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
    if (CV_EML_IF(0, 1, 2, c3_Tdes >= 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
      c3_pwms[0] = 0.0;
      c3_pwms[1] = c3_d;
      c3_pwms[2] = c3_d;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
      c3_pwms[0] = 0.0;
      c3_pwms[1] = c3_d;
      c3_pwms[2] = 0.0;
    }
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
    if (CV_EML_IF(0, 1, 3, c3_Tdes >= 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
      c3_pwms[0] = 0.0;
      c3_pwms[1] = 0.0;
      c3_pwms[2] = c3_d;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
      c3_pwms[0] = 0.0;
      c3_pwms[1] = c3_d;
      c3_pwms[2] = c3_d;
    }
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
    if (CV_EML_IF(0, 1, 4, c3_Tdes >= 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 47);
      c3_pwms[0] = c3_d;
      c3_pwms[1] = 0.0;
      c3_pwms[2] = c3_d;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
      c3_pwms[0] = 0.0;
      c3_pwms[1] = 0.0;
      c3_pwms[2] = c3_d;
    }
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
    if (CV_EML_IF(0, 1, 5, c3_Tdes >= 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
      c3_pwms[0] = c3_d;
      c3_pwms[1] = 0.0;
      c3_pwms[2] = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
      c3_pwms[0] = c3_d;
      c3_pwms[1] = 0.0;
      c3_pwms[2] = c3_d;
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
    for (c3_i2 = 0; c3_i2 < 3; c3_i2++) {
      c3_pwms[c3_i2] = 0.0;
    }
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    c3_a[c3_i0] = c3_pwms[c3_i0];
  }

  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    c3_pwms[c3_i1] = c3_a[c3_i1] * 1000.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
  c3_pwma = c3_pwms[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
  c3_pwmb = c3_pwms[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
  c3_pwmc = c3_pwms[2];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -67);
  sf_debug_symbol_scope_pop();
  *c3_b_pwma = c3_pwma;
  *c3_b_pwmb = c3_pwmb;
  *c3_b_pwmc = c3_pwmc;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_motor_control_with_off_the_shelf_SVPWM
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
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
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_pwmc, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_pwmc), &c3_thisId);
  sf_mex_destroy(&c3_pwmc);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
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
  const mxArray *c3_pwmc;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c3_pwmc = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_pwmc), &c3_thisId);
  sf_mex_destroy(&c3_pwmc);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i3;
  real_T c3_b_inData[3];
  int32_T c3_i4;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_b_inData[c3_i3] = (*(real_T (*)[3])c3_inData)[c3_i3];
  }

  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_u[c3_i4] = c3_b_inData[c3_i4];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[3])
{
  real_T c3_dv0[3];
  int32_T c3_i5;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_y[c3_i5] = c3_dv0[c3_i5];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_pwms;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i6;
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c3_pwms = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_pwms), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_pwms);
  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    (*(real_T (*)[3])c3_outData)[c3_i6] = c3_y[c3_i6];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_motor_control_with_off_the_shelf_SVPWM_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[14];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i7;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c3_i7 = 0; c3_i7 < 14; c3_i7++) {
    c3_r0 = &c3_info[c3_i7];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i7);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i7);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14])
{
  c3_info[0].context = "";
  c3_info[0].name = "mrdivide";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[0].fileTimeLo = 1325145738U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 1319751566U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].name = "rdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[1].fileTimeLo = 1286840444U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].name = "eml_div";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[2].fileTimeLo = 1313369410U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "";
  c3_info[3].name = "floor";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[3].fileTimeLo = 1286840342U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[4].name = "eml_scalar_floor";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[4].fileTimeLo = 1286840326U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "mpower";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[5].fileTimeLo = 1286840442U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[6].name = "power";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[6].fileTimeLo = 1307672840U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[7].name = "eml_scalar_eg";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[7].fileTimeLo = 1286840396U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[8].name = "eml_scalexp_alloc";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[8].fileTimeLo = 1286840396U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[9].name = "eml_scalar_floor";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[9].fileTimeLo = 1286840326U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "";
  c3_info[10].name = "sqrt";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[10].fileTimeLo = 1286840352U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[11].name = "eml_error";
  c3_info[11].dominantType = "char";
  c3_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[11].fileTimeLo = 1305339600U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[12].name = "eml_scalar_sqrt";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[12].fileTimeLo = 1286840338U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "";
  c3_info[13].name = "mtimes";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[13].fileTimeLo = 1289541292U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
}

static real_T c3_mpower
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_ak = c3_b_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static void c3_eml_error
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  int32_T c3_i8;
  static char_T c3_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i8 = 0; c3_i8 < 30; c3_i8++) {
    c3_u[c3_i8] = c3_varargin_1[c3_i8];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i9;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i9, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i9;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_b_is_active_c3_motor_control_with_off_the_shelf_SVPWM,
   const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_motor_control_with_off_the_shelf_SVPWM), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_motor_control_with_off_the_shelf_SVPWM);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info
  (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_motor_control_with_off_the_shelf_SVPWM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2792138223U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2366312465U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3709750342U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(593605800U);
}

mxArray *sf_c3_motor_control_with_off_the_shelf_SVPWM_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5LMTnlCeCvRNUd4vMXsdIG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
  *sf_get_sim_state_info_c3_motor_control_with_off_the_shelf_SVPWM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"pwma\",},{M[1],M[12],T\"pwmb\",},{M[1],M[13],T\"pwmc\",},{M[8],M[0],T\"is_active_c3_motor_control_with_off_the_shelf_SVPWM\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_motor_control_with_off_the_shelf_SVPWM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
    chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
           3,
           1,
           1,
           8,
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
            (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Valpha");
          _SFD_SET_DATA_PROPS(1,2,0,1,"pwma");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Vbeta");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Vdc");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Tdes");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(6,2,0,1,"pwmb");
          _SFD_SET_DATA_PROPS(7,2,0,1,"pwmc");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1145);
        _SFD_CV_INIT_EML_IF(0,1,0,178,189,242,302);
        _SFD_CV_INIT_EML_IF(0,1,1,322,333,386,446);
        _SFD_CV_INIT_EML_IF(0,1,2,475,486,539,599);
        _SFD_CV_INIT_EML_IF(0,1,3,619,630,683,743);
        _SFD_CV_INIT_EML_IF(0,1,4,763,774,827,887);
        _SFD_CV_INIT_EML_IF(0,1,5,907,918,971,1031);

        {
          static int caseStart[] = { 1045, 163, 307, 460, 604, 748, 892 };

          static int caseExprEnd[] = { 1054, 169, 313, 466, 610, 754, 898 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,148,159,1082,7,&(caseStart[0]),
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_Valpha;
          real_T *c3_pwma;
          real_T *c3_Vbeta;
          real_T *c3_Vdc;
          real_T *c3_Tdes;
          real_T *c3_Theta;
          real_T *c3_pwmb;
          real_T *c3_pwmc;
          c3_pwmc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_pwmb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_Tdes = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_Vbeta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_pwma = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Valpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Valpha);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_pwma);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Vbeta);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_Vdc);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_Tdes);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Theta);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_pwmb);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_pwmc);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "mxVPh2nJfptmdJL1P2WtD";
}

static void sf_opaque_initialize_c3_motor_control_with_off_the_shelf_SVPWM(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
  initialize_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c3_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  enable_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c3_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  disable_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c3_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  sf_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c3_motor_control_with_off_the_shelf_SVPWM();/* state var info */
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

extern void sf_internal_set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
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
    sf_get_sim_state_info_c3_motor_control_with_off_the_shelf_SVPWM();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM(S);
}

static void sf_opaque_set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM(S, st);
}

static void sf_opaque_terminate_c3_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_motor_control_with_off_the_shelf_SVPWM
      ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_motor_control_with_off_the_shelf_SVPWM_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_motor_control_with_off_the_shelf_SVPWM
    ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_motor_control_with_off_the_shelf_SVPWM
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_motor_control_with_off_the_shelf_SVPWM
      ((SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_motor_control_with_off_the_shelf_SVPWM(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_motor_control_with_off_the_shelf_SVPWM_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3859976325U));
  ssSetChecksum1(S,(3122289698U));
  ssSetChecksum2(S,(3275674240U));
  ssSetChecksum3(S,(3410458804U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_motor_control_with_off_the_shelf_SVPWM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_motor_control_with_off_the_shelf_SVPWM(SimStruct *S)
{
  SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    malloc(sizeof(SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_motor_control_with_off_the_shelf_SVPWMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c3_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_motor_control_with_off_the_shelf_SVPWM;
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

void c3_motor_control_with_off_the_shelf_SVPWM_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_motor_control_with_off_the_shelf_SVPWM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_motor_control_with_off_the_shelf_SVPWM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_motor_control_with_off_the_shelf_SVPWM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_motor_control_with_off_the_shelf_SVPWM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
