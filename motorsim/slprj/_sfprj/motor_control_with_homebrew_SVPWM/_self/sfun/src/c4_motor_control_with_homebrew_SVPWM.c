/* Include files */

#include "blascompat32.h"
#include "motor_control_with_homebrew_SVPWM_sfun.h"
#include "c4_motor_control_with_homebrew_SVPWM.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "motor_control_with_homebrew_SVPWM_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[19] = { "ang", "sext", "v1", "v2",
  "t1", "t2", "num", "den", "xint", "yint", "nargin", "nargout", "Va", "Vb",
  "Vdc", "s1", "dc1", "s2", "dc2" };

static const char * c4_b_debug_family_names[4] = { "nargin", "nargout", "h", "p"
};

static const char * c4_c_debug_family_names[4] = { "positiveInput", "nargin",
  "nargout", "lambda" };

/* Function Declarations */
static void initialize_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void initialize_params_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void enable_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void disable_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void set_sim_state_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void sf_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void c4_chartstep_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void initSimStructsc4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_dc2, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static creal_T c4_c_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_d_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[42]);
static real_T c4_angle(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance, creal_T c4_h);
static real_T c4_wrapTo2Pi(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *
  chartInstance, real_T c4_lambda);
static void c4_pol2cart(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance, real_T c4_th, real_T c4_r, real_T *c4_x, real_T *c4_y);
static real_T c4_mpower(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance, real_T c4_a);
static void c4_eml_error(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_f_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_motor_control_with_homebrew_SVPWM, const char_T
   *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_motor_control_with_homebrew_SVPWM = 0U;
}

static void initialize_params_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
}

static void enable_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
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
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_dc1;
  real_T *c4_dc2;
  real_T *c4_s1;
  real_T *c4_s2;
  c4_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(5), FALSE);
  c4_hoistedGlobal = *c4_dc1;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_dc2;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_s1;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_s2;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal =
    chartInstance->c4_is_active_c4_motor_control_with_homebrew_SVPWM;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_dc1;
  real_T *c4_dc2;
  real_T *c4_s1;
  real_T *c4_s2;
  c4_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_dc1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "dc1");
  *c4_dc2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "dc2");
  *c4_s1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
    "s1");
  *c4_s2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
    "s2");
  chartInstance->c4_is_active_c4_motor_control_with_homebrew_SVPWM =
    c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
    "is_active_c4_motor_control_with_homebrew_SVPWM");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_motor_control_with_homebrew_SVPWM(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
}

static void sf_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
  real_T *c4_Va;
  real_T *c4_s1;
  real_T *c4_dc1;
  real_T *c4_Vb;
  real_T *c4_s2;
  real_T *c4_Vdc;
  real_T *c4_dc2;
  c4_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_Va, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_s1, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_dc1, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_Vb, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_s2, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_Vdc, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_dc2, 6U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_motor_control_with_homebrew_SVPWM(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_motor_control_with_homebrew_SVPWMMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_Va;
  real_T c4_Vb;
  real_T c4_Vdc;
  uint32_T c4_debug_family_var_map[19];
  real_T c4_ang;
  real_T c4_sext;
  creal_T c4_v1;
  creal_T c4_v2;
  real_T c4_t1;
  real_T c4_t2;
  real_T c4_num;
  real_T c4_den;
  real_T c4_xint;
  real_T c4_yint;
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 4.0;
  real_T c4_s1;
  real_T c4_dc1;
  real_T c4_s2;
  real_T c4_dc2;
  real_T c4_b;
  static creal_T c4_dc0 = { 0.0, 1.0 };

  creal_T c4_y;
  creal_T c4_b_Va;
  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_d_x;
  static creal_T c4_b_dc1 = { 1.0, 1.0 };

  real_T c4_th;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_b_t1;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_b_t2;
  real_T c4_b_b;
  real_T c4_b_th;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_c_t1;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_c_t2;
  real_T c4_c_b;
  real_T c4_c_th;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_d_t1;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_d_t2;
  real_T c4_d_b;
  real_T c4_d_th;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_e_t1;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_e_t2;
  real_T c4_e_b;
  real_T c4_e_th;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_f_t1;
  real_T c4_w_x;
  real_T c4_x_x;
  real_T c4_f_t2;
  real_T c4_f_b;
  real_T c4_g_t2;
  real_T c4_g_t1;
  real_T c4_g_b;
  real_T c4_h_t2;
  real_T c4_h_t1;
  real_T c4_h_b;
  real_T c4_i_t2;
  real_T c4_i_t1;
  real_T c4_i_b;
  real_T c4_j_t2;
  real_T c4_j_t1;
  real_T c4_j_b;
  real_T c4_k_t2;
  real_T c4_k_t1;
  real_T c4_k_b;
  real_T c4_a;
  real_T c4_l_b;
  real_T c4_c_y;
  real_T c4_b_A;
  real_T c4_B;
  real_T c4_y_x;
  real_T c4_d_y;
  real_T c4_ab_x;
  real_T c4_e_y;
  real_T c4_f_y;
  real_T c4_c_A;
  real_T c4_b_B;
  real_T c4_bb_x;
  real_T c4_g_y;
  real_T c4_cb_x;
  real_T c4_h_y;
  real_T c4_i_y;
  real_T c4_d_A;
  real_T c4_c_B;
  real_T c4_db_x;
  real_T c4_j_y;
  real_T c4_eb_x;
  real_T c4_k_y;
  real_T c4_e_A;
  real_T c4_d_B;
  real_T c4_fb_x;
  real_T c4_l_y;
  real_T c4_gb_x;
  real_T c4_m_y;
  real_T c4_n_y;
  real_T c4_b_a;
  real_T c4_m_b;
  real_T c4_hb_x;
  real_T c4_ib_x;
  real_T c4_f_A;
  real_T c4_e_B;
  real_T c4_jb_x;
  real_T c4_o_y;
  real_T c4_kb_x;
  real_T c4_p_y;
  real_T c4_lb_x;
  real_T c4_mb_x;
  real_T c4_g_A;
  real_T c4_f_B;
  real_T c4_nb_x;
  real_T c4_q_y;
  real_T c4_ob_x;
  real_T c4_r_y;
  real_T *c4_b_dc2;
  real_T *c4_b_s2;
  real_T *c4_c_dc1;
  real_T *c4_b_s1;
  real_T *c4_b_Vdc;
  real_T *c4_b_Vb;
  real_T *c4_c_Va;
  c4_b_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_c_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_c_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_c_Va;
  c4_b_hoistedGlobal = *c4_b_Vb;
  c4_c_hoistedGlobal = *c4_b_Vdc;
  c4_Va = c4_hoistedGlobal;
  c4_Vb = c4_b_hoistedGlobal;
  c4_Vdc = c4_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 19U, 19U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_ang, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_sext, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_v1, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_v2, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_t1, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_t2, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_num, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_den, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_xint, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_yint, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_Va, 12U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_Vb, 13U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c4_Vdc, 14U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_s1, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_dc1, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_s2, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_dc2, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_b = c4_Vb;
  c4_y.re = c4_b * c4_dc0.re;
  c4_y.im = c4_b * c4_dc0.im;
  c4_b_Va.re = c4_Va + c4_y.re;
  c4_b_Va.im = c4_y.im;
  c4_ang = c4_wrapTo2Pi(chartInstance, c4_angle(chartInstance, c4_b_Va));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_A = c4_ang;
  c4_x = c4_A;
  c4_b_x = c4_x;
  c4_b_y = c4_b_x / 1.0471975511965976;
  c4_c_x = c4_b_y;
  c4_sext = c4_c_x;
  c4_d_x = c4_sext;
  c4_sext = c4_d_x;
  c4_sext = muDoubleScalarFloor(c4_sext);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_v1 = c4_b_dc1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_v2 = c4_b_dc1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  switch ((int32_T)_SFD_INTEGER_CHECK("sext", c4_sext)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
    c4_s1 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
    c4_v1.re = c4_Vdc;
    c4_v1.im = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
    c4_s2 = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
    c4_th = c4_Vdc;
    c4_e_x = c4_th;
    c4_f_x = c4_e_x;
    c4_f_x = muDoubleScalarCos(c4_f_x);
    c4_b_t1 = 1.0471975511965976 * c4_f_x;
    c4_g_x = c4_th;
    c4_h_x = c4_g_x;
    c4_h_x = muDoubleScalarSin(c4_h_x);
    c4_b_t2 = 1.0471975511965976 * c4_h_x;
    c4_t1 = c4_b_t1;
    c4_t2 = c4_b_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
    c4_b_b = c4_t2;
    c4_y.re = c4_b_b * c4_dc0.re;
    c4_y.im = c4_b_b * c4_dc0.im;
    c4_v2.re = c4_t1 + c4_y.re;
    c4_v2.im = c4_y.im;
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
    c4_s1 = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
    c4_b_th = c4_Vdc;
    c4_i_x = c4_b_th;
    c4_j_x = c4_i_x;
    c4_j_x = muDoubleScalarCos(c4_j_x);
    c4_c_t1 = 1.0471975511965976 * c4_j_x;
    c4_k_x = c4_b_th;
    c4_l_x = c4_k_x;
    c4_l_x = muDoubleScalarSin(c4_l_x);
    c4_c_t2 = 1.0471975511965976 * c4_l_x;
    c4_t1 = c4_c_t1;
    c4_t2 = c4_c_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
    c4_c_b = c4_t2;
    c4_y.re = c4_c_b * c4_dc0.re;
    c4_y.im = c4_c_b * c4_dc0.im;
    c4_v1.re = c4_t1 + c4_y.re;
    c4_v1.im = c4_y.im;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
    c4_s2 = 3.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
    c4_c_th = c4_Vdc;
    c4_m_x = c4_c_th;
    c4_n_x = c4_m_x;
    c4_n_x = muDoubleScalarCos(c4_n_x);
    c4_d_t1 = 2.0943951023931953 * c4_n_x;
    c4_o_x = c4_c_th;
    c4_p_x = c4_o_x;
    c4_p_x = muDoubleScalarSin(c4_p_x);
    c4_d_t2 = 2.0943951023931953 * c4_p_x;
    c4_t1 = c4_d_t1;
    c4_t2 = c4_d_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 34);
    c4_d_b = c4_t2;
    c4_y.re = c4_d_b * c4_dc0.re;
    c4_y.im = c4_d_b * c4_dc0.im;
    c4_v2.re = c4_t1 + c4_y.re;
    c4_v2.im = c4_y.im;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
    c4_s1 = 3.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
    c4_d_th = c4_Vdc;
    c4_q_x = c4_d_th;
    c4_r_x = c4_q_x;
    c4_r_x = muDoubleScalarCos(c4_r_x);
    c4_e_t1 = 2.0943951023931953 * c4_r_x;
    c4_s_x = c4_d_th;
    c4_t_x = c4_s_x;
    c4_t_x = muDoubleScalarSin(c4_t_x);
    c4_e_t2 = 2.0943951023931953 * c4_t_x;
    c4_t1 = c4_e_t1;
    c4_t2 = c4_e_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 39);
    c4_e_b = c4_t2;
    c4_y.re = c4_e_b * c4_dc0.re;
    c4_y.im = c4_e_b * c4_dc0.im;
    c4_v1.re = c4_t1 + c4_y.re;
    c4_v1.im = c4_y.im;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
    c4_s2 = 4.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 42);
    c4_e_th = c4_Vdc;
    c4_u_x = c4_e_th;
    c4_v_x = c4_u_x;
    c4_v_x = muDoubleScalarCos(c4_v_x);
    c4_f_t1 = 3.1415926535897931 * c4_v_x;
    c4_w_x = c4_e_th;
    c4_x_x = c4_w_x;
    c4_x_x = muDoubleScalarSin(c4_x_x);
    c4_f_t2 = 3.1415926535897931 * c4_x_x;
    c4_t1 = c4_f_t1;
    c4_t2 = c4_f_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
    c4_f_b = c4_t2;
    c4_y.re = c4_f_b * c4_dc0.re;
    c4_y.im = c4_f_b * c4_dc0.im;
    c4_v2.re = c4_t1 + c4_y.re;
    c4_v2.im = c4_y.im;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 45);
    c4_s1 = 4.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
    c4_pol2cart(chartInstance, c4_Vdc, 3.1415926535897931, &c4_g_t1, &c4_g_t2);
    c4_t1 = c4_g_t1;
    c4_t2 = c4_g_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
    c4_g_b = c4_t2;
    c4_y.re = c4_g_b * c4_dc0.re;
    c4_y.im = c4_g_b * c4_dc0.im;
    c4_v1.re = c4_t1 + c4_y.re;
    c4_v1.im = c4_y.im;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 49);
    c4_s2 = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 50);
    c4_pol2cart(chartInstance, c4_Vdc, 4.1887902047863905, &c4_h_t1, &c4_h_t2);
    c4_t1 = c4_h_t1;
    c4_t2 = c4_h_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 51);
    c4_h_b = c4_t2;
    c4_y.re = c4_h_b * c4_dc0.re;
    c4_y.im = c4_h_b * c4_dc0.im;
    c4_v2.re = c4_t1 + c4_y.re;
    c4_v2.im = c4_y.im;
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 53);
    c4_s1 = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 54);
    c4_pol2cart(chartInstance, c4_Vdc, 4.1887902047863905, &c4_i_t1, &c4_i_t2);
    c4_t1 = c4_i_t1;
    c4_t2 = c4_i_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
    c4_i_b = c4_t2;
    c4_y.re = c4_i_b * c4_dc0.re;
    c4_y.im = c4_i_b * c4_dc0.im;
    c4_v1.re = c4_t1 + c4_y.re;
    c4_v1.im = c4_y.im;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 58);
    c4_s2 = 6.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 59);
    c4_pol2cart(chartInstance, c4_Vdc, 5.2359877559829888, &c4_j_t1, &c4_j_t2);
    c4_t1 = c4_j_t1;
    c4_t2 = c4_j_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 60);
    c4_j_b = c4_t2;
    c4_y.re = c4_j_b * c4_dc0.re;
    c4_y.im = c4_j_b * c4_dc0.im;
    c4_v2.re = c4_t1 + c4_y.re;
    c4_v2.im = c4_y.im;
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 62);
    c4_s1 = 6.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 63);
    c4_pol2cart(chartInstance, c4_Vdc, 5.2359877559829888, &c4_k_t1, &c4_k_t2);
    c4_t1 = c4_k_t1;
    c4_t2 = c4_k_t2;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 64);
    c4_k_b = c4_t2;
    c4_y.re = c4_k_b * c4_dc0.re;
    c4_y.im = c4_k_b * c4_dc0.im;
    c4_v1.re = c4_t1 + c4_y.re;
    c4_v1.im = c4_y.im;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 66);
    c4_s2 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 67);
    c4_v2.re = c4_Vdc;
    c4_v2.im = 0.0;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 69);
    c4_s1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 70);
    c4_s2 = 0.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 76);
  c4_a = c4_v2.im;
  c4_l_b = c4_Vb;
  c4_c_y = c4_a * c4_l_b;
  c4_b_A = c4_c_y;
  c4_B = c4_v2.re;
  c4_y_x = c4_b_A;
  c4_d_y = c4_B;
  c4_ab_x = c4_y_x;
  c4_e_y = c4_d_y;
  c4_f_y = c4_ab_x / c4_e_y;
  c4_num = (c4_Va - c4_f_y) - c4_v1.im;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 77);
  c4_c_A = c4_v2.im;
  c4_b_B = c4_v2.re;
  c4_bb_x = c4_c_A;
  c4_g_y = c4_b_B;
  c4_cb_x = c4_bb_x;
  c4_h_y = c4_g_y;
  c4_i_y = c4_cb_x / c4_h_y;
  c4_den = c4_v1.re - c4_i_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 79);
  c4_d_A = c4_num;
  c4_c_B = c4_den;
  c4_db_x = c4_d_A;
  c4_j_y = c4_c_B;
  c4_eb_x = c4_db_x;
  c4_k_y = c4_j_y;
  c4_xint = c4_eb_x / c4_k_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 80);
  c4_e_A = c4_v1.im;
  c4_d_B = c4_v1.re;
  c4_fb_x = c4_e_A;
  c4_l_y = c4_d_B;
  c4_gb_x = c4_fb_x;
  c4_m_y = c4_l_y;
  c4_n_y = c4_gb_x / c4_m_y;
  c4_b_a = c4_n_y;
  c4_m_b = c4_xint;
  c4_yint = c4_b_a * c4_m_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 83);
  c4_hb_x = c4_mpower(chartInstance, c4_xint) + c4_mpower(chartInstance, c4_yint);
  c4_ib_x = c4_hb_x;
  if (c4_ib_x < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_ib_x = muDoubleScalarSqrt(c4_ib_x);
  c4_f_A = c4_ib_x;
  c4_e_B = c4_Vdc;
  c4_jb_x = c4_f_A;
  c4_o_y = c4_e_B;
  c4_kb_x = c4_jb_x;
  c4_p_y = c4_o_y;
  c4_dc1 = c4_kb_x / c4_p_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 88);
  c4_lb_x = c4_mpower(chartInstance, c4_xint - c4_Va) + c4_mpower(chartInstance,
    c4_yint - c4_Vb);
  c4_mb_x = c4_lb_x;
  if (c4_mb_x < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_mb_x = muDoubleScalarSqrt(c4_mb_x);
  c4_g_A = c4_mb_x;
  c4_f_B = c4_Vdc;
  c4_nb_x = c4_g_A;
  c4_q_y = c4_f_B;
  c4_ob_x = c4_nb_x;
  c4_r_y = c4_q_y;
  c4_dc2 = c4_ob_x / c4_r_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -88);
  sf_debug_symbol_scope_pop();
  *c4_b_s1 = c4_s1;
  *c4_c_dc1 = c4_dc1;
  *c4_b_s2 = c4_s2;
  *c4_b_dc2 = c4_dc2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_motor_control_with_homebrew_SVPWM
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
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
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_dc2, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dc2), &c4_thisId);
  sf_mex_destroy(&c4_dc2);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_dc2;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_dc2 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dc2), &c4_thisId);
  sf_mex_destroy(&c4_dc2);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  creal_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(creal_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 1U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static creal_T c4_c_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  creal_T c4_y;
  creal_T c4_dc2;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_dc2, 1, 0, 1U, 0, 0U, 0);
  c4_y = c4_dc2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_v2;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  creal_T c4_y;
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_v2 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_v2), &c4_thisId);
  sf_mex_destroy(&c4_v2);
  *(creal_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static boolean_T c4_d_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_positiveInput;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_positiveInput = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_positiveInput),
    &c4_thisId);
  sf_mex_destroy(&c4_positiveInput);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[42];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 42), FALSE);
  for (c4_i0 = 0; c4_i0 < 42; c4_i0++) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[42])
{
  c4_info[0].context = "";
  c4_info[0].name = "mtimes";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[0].fileTimeLo = 1289541292U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 0U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context = "";
  c4_info[1].name = "atan2";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c4_info[1].fileTimeLo = 1286840304U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c4_info[2].name = "eml_scalar_eg";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[2].fileTimeLo = 1286840396U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c4_info[3].name = "eml_scalexp_alloc";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[3].fileTimeLo = 1286840396U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c4_info[4].name = "eml_scalar_atan2";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c4_info[4].fileTimeLo = 1286840320U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context = "";
  c4_info[5].name = "mod";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c4_info[5].fileTimeLo = 1286840344U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c4_info[6].name = "eml_scalar_eg";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[6].fileTimeLo = 1286840396U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c4_info[7].name = "eml_scalexp_alloc";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[7].fileTimeLo = 1286840396U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/mod.m";
  c4_info[8].name = "eml_scalar_mod";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c4_info[8].fileTimeLo = 1307672838U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c4_info[9].name = "eml_scalar_eg";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[9].fileTimeLo = 1286840396U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c4_info[10].name = "eml_scalar_floor";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[10].fileTimeLo = 1286840326U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c4_info[11].name = "eml_scalar_round";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c4_info[11].fileTimeLo = 1307672838U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c4_info[12].name = "eml_scalar_abs";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[12].fileTimeLo = 1286840312U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
  c4_info[13].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c4_info[13].name = "eps";
  c4_info[13].dominantType = "char";
  c4_info[13].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c4_info[13].fileTimeLo = 1307672840U;
  c4_info[13].fileTimeHi = 0U;
  c4_info[13].mFileTimeLo = 0U;
  c4_info[13].mFileTimeHi = 0U;
  c4_info[14].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c4_info[14].name = "eml_is_float_class";
  c4_info[14].dominantType = "char";
  c4_info[14].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c4_info[14].fileTimeLo = 1286840382U;
  c4_info[14].fileTimeHi = 0U;
  c4_info[14].mFileTimeLo = 0U;
  c4_info[14].mFileTimeHi = 0U;
  c4_info[15].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c4_info[15].name = "eml_eps";
  c4_info[15].dominantType = "char";
  c4_info[15].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c4_info[15].fileTimeLo = 1307672840U;
  c4_info[15].fileTimeHi = 0U;
  c4_info[15].mFileTimeLo = 0U;
  c4_info[15].mFileTimeHi = 0U;
  c4_info[16].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c4_info[16].name = "eml_float_model";
  c4_info[16].dominantType = "char";
  c4_info[16].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c4_info[16].fileTimeLo = 1307672842U;
  c4_info[16].fileTimeHi = 0U;
  c4_info[16].mFileTimeLo = 0U;
  c4_info[16].mFileTimeHi = 0U;
  c4_info[17].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m!local_scalar_mod";
  c4_info[17].name = "mtimes";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[17].fileTimeLo = 1289541292U;
  c4_info[17].fileTimeHi = 0U;
  c4_info[17].mFileTimeLo = 0U;
  c4_info[17].mFileTimeHi = 0U;
  c4_info[18].context = "";
  c4_info[18].name = "eml_li_find";
  c4_info[18].dominantType = "";
  c4_info[18].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c4_info[18].fileTimeLo = 1286840386U;
  c4_info[18].fileTimeHi = 0U;
  c4_info[18].mFileTimeLo = 0U;
  c4_info[18].mFileTimeHi = 0U;
  c4_info[19].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c4_info[19].name = "eml_index_class";
  c4_info[19].dominantType = "";
  c4_info[19].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[19].fileTimeLo = 1286840378U;
  c4_info[19].fileTimeHi = 0U;
  c4_info[19].mFileTimeLo = 0U;
  c4_info[19].mFileTimeHi = 0U;
  c4_info[20].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c4_info[20].name = "eml_index_class";
  c4_info[20].dominantType = "";
  c4_info[20].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[20].fileTimeLo = 1286840378U;
  c4_info[20].fileTimeHi = 0U;
  c4_info[20].mFileTimeLo = 0U;
  c4_info[20].mFileTimeHi = 0U;
  c4_info[21].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c4_info[21].name = "eml_index_plus";
  c4_info[21].dominantType = "int32";
  c4_info[21].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c4_info[21].fileTimeLo = 1286840378U;
  c4_info[21].fileTimeHi = 0U;
  c4_info[21].mFileTimeLo = 0U;
  c4_info[21].mFileTimeHi = 0U;
  c4_info[22].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c4_info[22].name = "eml_index_class";
  c4_info[22].dominantType = "";
  c4_info[22].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[22].fileTimeLo = 1286840378U;
  c4_info[22].fileTimeHi = 0U;
  c4_info[22].mFileTimeLo = 0U;
  c4_info[22].mFileTimeHi = 0U;
  c4_info[23].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c4_info[23].name = "eml_index_plus";
  c4_info[23].dominantType = "int32";
  c4_info[23].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c4_info[23].fileTimeLo = 1286840378U;
  c4_info[23].fileTimeHi = 0U;
  c4_info[23].mFileTimeLo = 0U;
  c4_info[23].mFileTimeHi = 0U;
  c4_info[24].context = "";
  c4_info[24].name = "mrdivide";
  c4_info[24].dominantType = "double";
  c4_info[24].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[24].fileTimeLo = 1325145738U;
  c4_info[24].fileTimeHi = 0U;
  c4_info[24].mFileTimeLo = 1319751566U;
  c4_info[24].mFileTimeHi = 0U;
  c4_info[25].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[25].name = "rdivide";
  c4_info[25].dominantType = "double";
  c4_info[25].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[25].fileTimeLo = 1286840444U;
  c4_info[25].fileTimeHi = 0U;
  c4_info[25].mFileTimeLo = 0U;
  c4_info[25].mFileTimeHi = 0U;
  c4_info[26].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[26].name = "eml_div";
  c4_info[26].dominantType = "double";
  c4_info[26].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[26].fileTimeLo = 1313369410U;
  c4_info[26].fileTimeHi = 0U;
  c4_info[26].mFileTimeLo = 0U;
  c4_info[26].mFileTimeHi = 0U;
  c4_info[27].context = "";
  c4_info[27].name = "floor";
  c4_info[27].dominantType = "double";
  c4_info[27].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c4_info[27].fileTimeLo = 1286840342U;
  c4_info[27].fileTimeHi = 0U;
  c4_info[27].mFileTimeLo = 0U;
  c4_info[27].mFileTimeHi = 0U;
  c4_info[28].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c4_info[28].name = "eml_scalar_floor";
  c4_info[28].dominantType = "double";
  c4_info[28].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[28].fileTimeLo = 1286840326U;
  c4_info[28].fileTimeHi = 0U;
  c4_info[28].mFileTimeLo = 0U;
  c4_info[28].mFileTimeHi = 0U;
  c4_info[29].context = "";
  c4_info[29].name = "pol2cart";
  c4_info[29].dominantType = "double";
  c4_info[29].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c4_info[29].fileTimeLo = 1286840454U;
  c4_info[29].fileTimeHi = 0U;
  c4_info[29].mFileTimeLo = 0U;
  c4_info[29].mFileTimeHi = 0U;
  c4_info[30].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c4_info[30].name = "cos";
  c4_info[30].dominantType = "double";
  c4_info[30].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[30].fileTimeLo = 1286840306U;
  c4_info[30].fileTimeHi = 0U;
  c4_info[30].mFileTimeLo = 0U;
  c4_info[30].mFileTimeHi = 0U;
  c4_info[31].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[31].name = "eml_scalar_cos";
  c4_info[31].dominantType = "double";
  c4_info[31].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c4_info[31].fileTimeLo = 1286840322U;
  c4_info[31].fileTimeHi = 0U;
  c4_info[31].mFileTimeLo = 0U;
  c4_info[31].mFileTimeHi = 0U;
  c4_info[32].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/pol2cart.m";
  c4_info[32].name = "sin";
  c4_info[32].dominantType = "double";
  c4_info[32].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[32].fileTimeLo = 1286840350U;
  c4_info[32].fileTimeHi = 0U;
  c4_info[32].mFileTimeLo = 0U;
  c4_info[32].mFileTimeHi = 0U;
  c4_info[33].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[33].name = "eml_scalar_sin";
  c4_info[33].dominantType = "double";
  c4_info[33].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c4_info[33].fileTimeLo = 1286840336U;
  c4_info[33].fileTimeHi = 0U;
  c4_info[33].mFileTimeLo = 0U;
  c4_info[33].mFileTimeHi = 0U;
  c4_info[34].context = "";
  c4_info[34].name = "mpower";
  c4_info[34].dominantType = "double";
  c4_info[34].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[34].fileTimeLo = 1286840442U;
  c4_info[34].fileTimeHi = 0U;
  c4_info[34].mFileTimeLo = 0U;
  c4_info[34].mFileTimeHi = 0U;
  c4_info[35].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[35].name = "power";
  c4_info[35].dominantType = "double";
  c4_info[35].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[35].fileTimeLo = 1307672840U;
  c4_info[35].fileTimeHi = 0U;
  c4_info[35].mFileTimeLo = 0U;
  c4_info[35].mFileTimeHi = 0U;
  c4_info[36].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[36].name = "eml_scalar_eg";
  c4_info[36].dominantType = "double";
  c4_info[36].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[36].fileTimeLo = 1286840396U;
  c4_info[36].fileTimeHi = 0U;
  c4_info[36].mFileTimeLo = 0U;
  c4_info[36].mFileTimeHi = 0U;
  c4_info[37].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[37].name = "eml_scalexp_alloc";
  c4_info[37].dominantType = "double";
  c4_info[37].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[37].fileTimeLo = 1286840396U;
  c4_info[37].fileTimeHi = 0U;
  c4_info[37].mFileTimeLo = 0U;
  c4_info[37].mFileTimeHi = 0U;
  c4_info[38].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[38].name = "eml_scalar_floor";
  c4_info[38].dominantType = "double";
  c4_info[38].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[38].fileTimeLo = 1286840326U;
  c4_info[38].fileTimeHi = 0U;
  c4_info[38].mFileTimeLo = 0U;
  c4_info[38].mFileTimeHi = 0U;
  c4_info[39].context = "";
  c4_info[39].name = "sqrt";
  c4_info[39].dominantType = "double";
  c4_info[39].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[39].fileTimeLo = 1286840352U;
  c4_info[39].fileTimeHi = 0U;
  c4_info[39].mFileTimeLo = 0U;
  c4_info[39].mFileTimeHi = 0U;
  c4_info[40].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[40].name = "eml_error";
  c4_info[40].dominantType = "char";
  c4_info[40].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[40].fileTimeLo = 1305339600U;
  c4_info[40].fileTimeHi = 0U;
  c4_info[40].mFileTimeLo = 0U;
  c4_info[40].mFileTimeHi = 0U;
  c4_info[41].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[41].name = "eml_scalar_sqrt";
  c4_info[41].dominantType = "double";
  c4_info[41].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[41].fileTimeLo = 1286840338U;
  c4_info[41].fileTimeHi = 0U;
  c4_info[41].mFileTimeLo = 0U;
  c4_info[41].mFileTimeHi = 0U;
}

static real_T c4_angle(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance, creal_T c4_h)
{
  real_T c4_p;
  uint32_T c4_debug_family_var_map[4];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_y;
  real_T c4_x;
  real_T c4_b_y;
  real_T c4_b_x;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_h, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_p, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 123);
  c4_y = c4_h.im;
  c4_x = c4_h.re;
  c4_b_y = c4_y;
  c4_b_x = c4_x;
  c4_p = muDoubleScalarAtan2(c4_b_y, c4_b_x);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -123);
  sf_debug_symbol_scope_pop();
  return c4_p;
}

static real_T c4_wrapTo2Pi(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *
  chartInstance, real_T c4_lambda)
{
  real_T c4_b_lambda;
  uint32_T c4_debug_family_var_map[4];
  boolean_T c4_positiveInput;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_x;
  real_T c4_xk;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_y;
  real_T c4_g_x;
  real_T c4_b_y;
  real_T c4_b;
  real_T c4_c_y;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_dv0[1];
  boolean_T c4_b1;
  boolean_T c4_b_positiveInput;
  boolean_T c4_j_x;
  boolean_T c4_k_x;
  int32_T c4_k;
  int32_T c4_tmp_sizes[2];
  int32_T c4_iv0[2];
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_loop_ub;
  int32_T c4_i3;
  int32_T c4_tmp_data[1];
  int32_T c4_i4;
  int32_T c4_b_tmp_sizes[2];
  int32_T c4_b_tmp_data[1];
  int32_T c4_b_loop_ub;
  int32_T c4_i5;
  sf_debug_symbol_scope_push_eml(0U, 4U, 5U, c4_c_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_positiveInput, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_lambda, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_b_lambda, MAX_uint32_T,
    c4_sf_marshallOut, c4_sf_marshallIn);
  c4_b_lambda = c4_lambda;
  sf_debug_symbol_switch(3U, 4U);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 105);
  c4_positiveInput = (c4_b_lambda > 0.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 106);
  c4_x = c4_b_lambda;
  c4_xk = c4_x;
  c4_b_x = c4_xk;
  c4_c_x = c4_b_x;
  c4_b_lambda = c4_c_x / 6.2831853071795862;
  c4_d_x = c4_b_lambda;
  c4_e_x = c4_d_x;
  c4_e_x = muDoubleScalarRound(c4_e_x);
  c4_f_x = c4_b_lambda - c4_e_x;
  c4_y = muDoubleScalarAbs(c4_f_x);
  c4_g_x = c4_b_lambda;
  c4_b_y = muDoubleScalarAbs(c4_g_x);
  c4_b = c4_b_y;
  c4_c_y = 2.2204460492503131E-16 * c4_b;
  if (c4_y <= c4_c_y) {
    c4_b_lambda = 0.0;
  } else {
    c4_h_x = c4_b_lambda;
    c4_i_x = c4_h_x;
    c4_i_x = muDoubleScalarFloor(c4_i_x);
    c4_b_lambda = (c4_b_lambda - c4_i_x) * 6.2831853071795862;
  }

  sf_debug_symbol_switch(3U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 107);
  c4_dv0[0] = c4_b_lambda;
  c4_b1 = (c4_b_lambda == 0.0);
  c4_b_positiveInput = c4_positiveInput;
  c4_j_x = (c4_b1 && c4_b_positiveInput);
  c4_k_x = c4_j_x;
  c4_k = 0;
  if (c4_k_x) {
    c4_k = 1;
  }

  c4_tmp_sizes[0] = 1;
  c4_iv0[0] = 1;
  c4_iv0[1] = c4_k;
  c4_tmp_sizes[1] = c4_iv0[1];
  c4_i1 = c4_tmp_sizes[0];
  c4_i2 = c4_tmp_sizes[1];
  c4_loop_ub = c4_k - 1;
  for (c4_i3 = 0; c4_i3 <= c4_loop_ub; c4_i3++) {
    c4_tmp_data[c4_i3] = 0;
  }

  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    c4_b_tmp_sizes[c4_i4] = c4_tmp_sizes[c4_i4];
  }

  if (c4_j_x) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c4_b_tmp_sizes[1], 1, 0);
    c4_b_tmp_data[0] = 1;
  }

  c4_b_loop_ub = c4_b_tmp_sizes[0] * c4_b_tmp_sizes[1] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_b_loop_ub; c4_i5++) {
    c4_dv0[c4_b_tmp_data[c4_i5] - 1] = 6.2831853071795862;
  }

  c4_b_lambda = c4_dv0[0];
  sf_debug_symbol_switch(3U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -107);
  sf_debug_symbol_scope_pop();
  return c4_b_lambda;
}

static void c4_pol2cart(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance, real_T c4_th, real_T c4_r, real_T *c4_x, real_T *c4_y)
{
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  c4_b_x = c4_th;
  c4_c_x = c4_b_x;
  c4_c_x = muDoubleScalarCos(c4_c_x);
  *c4_x = c4_r * c4_c_x;
  c4_d_x = c4_th;
  c4_e_x = c4_d_x;
  c4_e_x = muDoubleScalarSin(c4_e_x);
  *c4_y = c4_r * c4_e_x;
}

static real_T c4_mpower(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance, real_T c4_a)
{
  real_T c4_b_a;
  real_T c4_ak;
  c4_b_a = c4_a;
  c4_ak = c4_b_a;
  return muDoubleScalarPower(c4_ak, 2.0);
}

static void c4_eml_error(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct
  *chartInstance)
{
  int32_T c4_i6;
  static char_T c4_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[30];
  const mxArray *c4_y = NULL;
  for (c4_i6 = 0; c4_i6 < 30; c4_i6++) {
    c4_u[c4_i6] = c4_varargin_1[c4_i6];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c4_y));
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i7;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i7, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i7;
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
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_f_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_motor_control_with_homebrew_SVPWM, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_motor_control_with_homebrew_SVPWM), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_motor_control_with_homebrew_SVPWM);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_motor_control_with_homebrew_SVPWM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2348666318U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3378433328U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2097312942U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2868940791U);
}

mxArray *sf_c4_motor_control_with_homebrew_SVPWM_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AGGB6tw8DZUdYQy0kfqJlG");
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

static const mxArray *sf_get_sim_state_info_c4_motor_control_with_homebrew_SVPWM
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[9],T\"dc1\",},{M[1],M[10],T\"dc2\",},{M[1],M[5],T\"s1\",},{M[1],M[7],T\"s2\",},{M[8],M[0],T\"is_active_c4_motor_control_with_homebrew_SVPWM\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_motor_control_with_homebrew_SVPWM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
    chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_motor_control_with_homebrew_SVPWMMachineNumber_,
           4,
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
            (_motor_control_with_homebrew_SVPWMMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_motor_control_with_homebrew_SVPWMMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_motor_control_with_homebrew_SVPWMMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2327);
        _SFD_CV_INIT_EML_FCN(0,1,"wrapTo2Pi",2329,-1,2922);
        _SFD_CV_INIT_EML_FCN(0,2,"angle",2924,-1,3280);

        {
          static int caseStart[] = { 1751, 552, 725, 948, 1156, 1364, 1589 };

          static int caseExprEnd[] = { 1760, 558, 731, 954, 1162, 1370, 1595 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,532,544,1808,7,&(caseStart[0]),
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
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_Va;
          real_T *c4_s1;
          real_T *c4_dc1;
          real_T *c4_Vb;
          real_T *c4_s2;
          real_T *c4_Vdc;
          real_T *c4_dc2;
          c4_dc2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_Vdc = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_s2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_Vb = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_dc1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_s1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_Va = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_Va);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_s1);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_dc1);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_Vb);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_s2);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_Vdc);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_dc2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_motor_control_with_homebrew_SVPWMMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "itPbERDg5H0QOWtNwUk4fD";
}

static void sf_opaque_initialize_c4_motor_control_with_homebrew_SVPWM(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
  initialize_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_motor_control_with_homebrew_SVPWM(void
  *chartInstanceVar)
{
  enable_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_motor_control_with_homebrew_SVPWM(void
  *chartInstanceVar)
{
  disable_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_motor_control_with_homebrew_SVPWM(void
  *chartInstanceVar)
{
  sf_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c4_motor_control_with_homebrew_SVPWM(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c4_motor_control_with_homebrew_SVPWM();/* state var info */
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

extern void sf_internal_set_sim_state_c4_motor_control_with_homebrew_SVPWM
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
    sf_get_sim_state_info_c4_motor_control_with_homebrew_SVPWM();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c4_motor_control_with_homebrew_SVPWM(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_motor_control_with_homebrew_SVPWM(S);
}

static void sf_opaque_set_sim_state_c4_motor_control_with_homebrew_SVPWM
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_motor_control_with_homebrew_SVPWM(S, st);
}

static void sf_opaque_terminate_c4_motor_control_with_homebrew_SVPWM(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_motor_control_with_homebrew_SVPWM
      ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_motor_control_with_homebrew_SVPWM_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_motor_control_with_homebrew_SVPWM
    ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_motor_control_with_homebrew_SVPWM(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_motor_control_with_homebrew_SVPWM
      ((SFc4_motor_control_with_homebrew_SVPWMInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_motor_control_with_homebrew_SVPWM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_motor_control_with_homebrew_SVPWM_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(792850996U));
  ssSetChecksum1(S,(3523055123U));
  ssSetChecksum2(S,(1878838494U));
  ssSetChecksum3(S,(540713522U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_motor_control_with_homebrew_SVPWM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_motor_control_with_homebrew_SVPWM(SimStruct *S)
{
  SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *chartInstance;
  chartInstance = (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct *)malloc
    (sizeof(SFc4_motor_control_with_homebrew_SVPWMInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_motor_control_with_homebrew_SVPWMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c4_motor_control_with_homebrew_SVPWM;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_motor_control_with_homebrew_SVPWM;
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

void c4_motor_control_with_homebrew_SVPWM_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_motor_control_with_homebrew_SVPWM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_motor_control_with_homebrew_SVPWM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_motor_control_with_homebrew_SVPWM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_motor_control_with_homebrew_SVPWM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
