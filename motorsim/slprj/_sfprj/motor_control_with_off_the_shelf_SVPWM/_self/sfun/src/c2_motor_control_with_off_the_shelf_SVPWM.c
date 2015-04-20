/* Include files */

#include "blascompat32.h"
#include "motor_control_with_off_the_shelf_SVPWM_sfun.h"
#include "c2_motor_control_with_off_the_shelf_SVPWM.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "motor_control_with_off_the_shelf_SVPWM_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[10] = { "nargin", "nargout", "ha",
  "hb", "hc", "time", "omega", "theta", "omegaInterp", "tracking" };

/* Function Declarations */
static void initialize_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void initialize_params_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void enable_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void disable_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_motor_control_with_off_the_shelf_SVP
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_st);
static void finalize_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void sf_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void initSimStructsc2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static real_T c2_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_omega, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_b_is_active_c2_motor_control_with_off_the_shelf_SVPWM,
   const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_motor_control_with_off_the_shelf_SVPWM = 0U;
}

static void initialize_params_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static void enable_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_motor_control_with_off_the_shelf_SVP
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_omega;
  real_T *c2_omegaInterp;
  real_T *c2_theta;
  real_T *c2_tracking;
  c2_tracking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_omegaInterp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  c2_hoistedGlobal = *c2_omega;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_omegaInterp;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_theta;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_tracking;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal =
    chartInstance->c2_is_active_c2_motor_control_with_off_the_shelf_SVPWM;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_omega;
  real_T *c2_omegaInterp;
  real_T *c2_theta;
  real_T *c2_tracking;
  c2_tracking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_omegaInterp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_omega = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "omega");
  *c2_omegaInterp = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "omegaInterp");
  *c2_theta = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "theta");
  *c2_tracking = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "tracking");
  chartInstance->c2_is_active_c2_motor_control_with_off_the_shelf_SVPWM =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "is_active_c2_motor_control_with_off_the_shelf_SVPWM");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_motor_control_with_off_the_shelf_SVP(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static void sf_c2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_ha;
  real_T c2_hb;
  real_T c2_hc;
  real_T c2_time;
  uint32_T c2_debug_family_var_map[10];
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 4.0;
  real_T c2_omega;
  real_T c2_theta;
  real_T c2_omegaInterp;
  real_T c2_tracking;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_m0 = NULL;
  const mxArray *c2_m1 = NULL;
  const mxArray *c2_m2 = NULL;
  const mxArray *c2_m3 = NULL;
  const mxArray *c2_b_omega = NULL;
  const mxArray *c2_b_theta = NULL;
  const mxArray *c2_b_omegaInterp = NULL;
  const mxArray *c2_b_tracking = NULL;
  real_T *c2_c_omega;
  real_T *c2_b_ha;
  real_T *c2_c_theta;
  real_T *c2_b_hb;
  real_T *c2_b_hc;
  real_T *c2_c_omegaInterp;
  real_T *c2_b_time;
  real_T *c2_c_tracking;
  c2_c_tracking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_c_omegaInterp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_hc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_hb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_c_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_ha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_c_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_c_omega, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ha, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_c_theta, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_hb, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_hc, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_c_omegaInterp, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_time, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_c_tracking, 7U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_ha;
  c2_b_hoistedGlobal = *c2_b_hb;
  c2_c_hoistedGlobal = *c2_b_hc;
  c2_d_hoistedGlobal = *c2_b_time;
  c2_ha = c2_hoistedGlobal;
  c2_hb = c2_b_hoistedGlobal;
  c2_hc = c2_c_hoistedGlobal;
  c2_time = c2_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_ha, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_hb, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_hc, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_time, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_omega, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_omegaInterp, 8U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_tracking, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_omega = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_theta = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_omegaInterp = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  sf_mex_printf("%s =\\n", "time");
  c2_u = c2_time;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_tracking = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_b_u = c2_ha;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_c_u = c2_hb;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_d_u = c2_hc;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  c2_e_u = c2_time;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("rotor_estimate", 4U, 4U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y,
                    14, c2_e_y, &c2_m3, &c2_m2, &c2_m1, &c2_m0);
  sf_mex_assign(&c2_b_omega, sf_mex_dup(c2_m3), FALSE);
  sf_mex_assign(&c2_b_theta, sf_mex_dup(c2_m2), FALSE);
  sf_mex_assign(&c2_b_omegaInterp, sf_mex_dup(c2_m1), FALSE);
  sf_mex_assign(&c2_b_tracking, sf_mex_dup(c2_m0), FALSE);
  c2_omega = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_omega), "omega");
  c2_theta = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_theta), "theta");
  c2_omegaInterp = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_omegaInterp), "omegaInterp");
  c2_tracking = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tracking),
    "tracking");
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c2_b_omega);
  sf_mex_destroy(&c2_b_theta);
  sf_mex_destroy(&c2_b_omegaInterp);
  sf_mex_destroy(&c2_b_tracking);
  sf_mex_destroy(&c2_m0);
  sf_mex_destroy(&c2_m1);
  sf_mex_destroy(&c2_m2);
  sf_mex_destroy(&c2_m3);
  *c2_c_omega = c2_omega;
  *c2_c_theta = c2_theta;
  *c2_c_omegaInterp = c2_omegaInterp;
  *c2_c_tracking = c2_tracking;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_motor_control_with_off_the_shelf_SVPWM
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_omega;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c2_omega = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_omega), &c2_thisId);
  sf_mex_destroy(&c2_omega);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_motor_control_with_off_the_shelf_SVPWM_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static real_T c2_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_omega, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_omega), &c2_thisId);
  sf_mex_destroy(&c2_omega);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_b_is_active_c2_motor_control_with_off_the_shelf_SVPWM,
   const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_motor_control_with_off_the_shelf_SVPWM), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_motor_control_with_off_the_shelf_SVPWM);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance,
   const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_motor_control_with_off_the_shelf_SVPWM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1317654075U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(319705812U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(146001194U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2882294445U);
}

mxArray *sf_c2_motor_control_with_off_the_shelf_SVPWM_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4a5oG7LwFaxQG4sngRR1FF");
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
  *sf_get_sim_state_info_c2_motor_control_with_off_the_shelf_SVPWM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[8],T\"omega\",},{M[1],M[9],T\"omegaInterp\",},{M[1],M[5],T\"theta\",},{M[1],M[11],T\"tracking\",},{M[8],M[0],T\"is_active_c2_motor_control_with_off_the_shelf_SVPWM\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_motor_control_with_off_the_shelf_SVPWM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
    chartInstance = (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_motor_control_with_off_the_shelf_SVPWMMachineNumber_,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"omega");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ha");
          _SFD_SET_DATA_PROPS(2,2,0,1,"theta");
          _SFD_SET_DATA_PROPS(3,1,1,0,"hb");
          _SFD_SET_DATA_PROPS(4,1,1,0,"hc");
          _SFD_SET_DATA_PROPS(5,2,0,1,"omegaInterp");
          _SFD_SET_DATA_PROPS(6,1,1,0,"time");
          _SFD_SET_DATA_PROPS(7,2,0,1,"tracking");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,409);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_omega;
          real_T *c2_ha;
          real_T *c2_theta;
          real_T *c2_hb;
          real_T *c2_hc;
          real_T *c2_omegaInterp;
          real_T *c2_time;
          real_T *c2_tracking;
          c2_tracking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_omegaInterp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_hc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_hb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_ha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_omega = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_omega);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_ha);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_theta);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_hb);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_hc);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_omegaInterp);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_time);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_tracking);
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
  return "RdONB4WRc6kc87UVLKOpz";
}

static void sf_opaque_initialize_c2_motor_control_with_off_the_shelf_SVPWM(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
  initialize_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c2_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  enable_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c2_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  disable_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c2_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  sf_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_motor_control_with_off_the_shelf_SVPWM();/* state var info */
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

extern void sf_internal_set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
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
    sf_get_sim_state_info_c2_motor_control_with_off_the_shelf_SVPWM();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM(S);
}

static void sf_opaque_set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM(S, st);
}

static void sf_opaque_terminate_c2_motor_control_with_off_the_shelf_SVPWM(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_motor_control_with_off_the_shelf_SVPWM
      ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
       chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_motor_control_with_off_the_shelf_SVPWM_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_motor_control_with_off_the_shelf_SVPWM
    ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_motor_control_with_off_the_shelf_SVPWM
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_motor_control_with_off_the_shelf_SVPWM
      ((SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_motor_control_with_off_the_shelf_SVPWM(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_motor_control_with_off_the_shelf_SVPWM_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(989400485U));
  ssSetChecksum1(S,(1162544890U));
  ssSetChecksum2(S,(426738388U));
  ssSetChecksum3(S,(1960151002U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_motor_control_with_off_the_shelf_SVPWM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_motor_control_with_off_the_shelf_SVPWM(SimStruct *S)
{
  SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct *)
    malloc(sizeof(SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_motor_control_with_off_the_shelf_SVPWMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_motor_control_with_off_the_shelf_SVPWM;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_motor_control_with_off_the_shelf_SVPWM;
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

void c2_motor_control_with_off_the_shelf_SVPWM_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_motor_control_with_off_the_shelf_SVPWM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_motor_control_with_off_the_shelf_SVPWM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_motor_control_with_off_the_shelf_SVPWM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_motor_control_with_off_the_shelf_SVPWM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
