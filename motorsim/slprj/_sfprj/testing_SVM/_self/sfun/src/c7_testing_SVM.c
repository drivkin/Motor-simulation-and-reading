/* Include files */

#include "blascompat32.h"
#include "testing_SVM_sfun.h"
#include "c7_testing_SVM.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testing_SVM_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[18] = { "d1", "d2", "p2", "d0", "p0",
  "p1", "nargin", "nargout", "s1", "dc1", "s2", "dc2", "dca", "dcb", "dcc", "pa",
  "pb", "pc" };

/* Function Declarations */
static void initialize_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance);
static void initialize_params_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance);
static void enable_c7_testing_SVM(SFc7_testing_SVMInstanceStruct *chartInstance);
static void disable_c7_testing_SVM(SFc7_testing_SVMInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_testing_SVM
  (SFc7_testing_SVMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_testing_SVM
  (SFc7_testing_SVMInstanceStruct *chartInstance);
static void set_sim_state_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance);
static void sf_c7_testing_SVM(SFc7_testing_SVMInstanceStruct *chartInstance);
static void c7_chartstep_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance);
static void initSimStructsc7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct *chartInstance,
  const mxArray *c7_pc, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_c_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_d_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_testing_SVM, const char_T
  *c7_identifier);
static uint8_T c7_e_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_testing_SVMInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_testing_SVM = 0U;
}

static void initialize_params_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance)
{
}

static void enable_c7_testing_SVM(SFc7_testing_SVMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_testing_SVM(SFc7_testing_SVMInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_testing_SVM
  (SFc7_testing_SVMInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_testing_SVM
  (SFc7_testing_SVMInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_d_hoistedGlobal;
  real_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T c7_e_hoistedGlobal;
  real_T c7_e_u;
  const mxArray *c7_f_y = NULL;
  real_T c7_f_hoistedGlobal;
  real_T c7_f_u;
  const mxArray *c7_g_y = NULL;
  uint8_T c7_g_hoistedGlobal;
  uint8_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  real_T *c7_dca;
  real_T *c7_dcb;
  real_T *c7_dcc;
  real_T *c7_pa;
  real_T *c7_pb;
  real_T *c7_pc;
  c7_pc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_pb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_pa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_dcc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_dcb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_dca = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(7), FALSE);
  c7_hoistedGlobal = *c7_dca;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *c7_dcb;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *c7_dcc;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = *c7_pa;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = *c7_pb;
  c7_e_u = c7_e_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = *c7_pc;
  c7_f_u = c7_f_hoistedGlobal;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = chartInstance->c7_is_active_c7_testing_SVM;
  c7_g_u = c7_g_hoistedGlobal;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_dca;
  real_T *c7_dcb;
  real_T *c7_dcc;
  real_T *c7_pa;
  real_T *c7_pb;
  real_T *c7_pc;
  c7_pc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_pb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_pa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_dcc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_dcb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_dca = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_dca = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)),
    "dca");
  *c7_dcb = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
    "dcb");
  *c7_dcc = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 2)),
    "dcc");
  *c7_pa = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 3)),
    "pa");
  *c7_pb = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 4)),
    "pb");
  *c7_pc = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 5)),
    "pc");
  chartInstance->c7_is_active_c7_testing_SVM = c7_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 6)),
     "is_active_c7_testing_SVM");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_testing_SVM(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance)
{
}

static void sf_c7_testing_SVM(SFc7_testing_SVMInstanceStruct *chartInstance)
{
  real_T *c7_s1;
  real_T *c7_dca;
  real_T *c7_dc1;
  real_T *c7_s2;
  real_T *c7_dc2;
  real_T *c7_dcb;
  real_T *c7_dcc;
  real_T *c7_pa;
  real_T *c7_pb;
  real_T *c7_pc;
  c7_pc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_pb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_pa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_dcc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_dcb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_dca = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_s1, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_dca, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_dc1, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_s2, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_dc2, 4U);
  _SFD_DATA_RANGE_CHECK(*c7_dcb, 5U);
  _SFD_DATA_RANGE_CHECK(*c7_dcc, 6U);
  _SFD_DATA_RANGE_CHECK(*c7_pa, 7U);
  _SFD_DATA_RANGE_CHECK(*c7_pb, 8U);
  _SFD_DATA_RANGE_CHECK(*c7_pc, 9U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_testing_SVM(chartInstance);
  sf_debug_check_for_state_inconsistency(_testing_SVMMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_chartstep_c7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  real_T c7_d_hoistedGlobal;
  real_T c7_s1;
  real_T c7_dc1;
  real_T c7_s2;
  real_T c7_dc2;
  uint32_T c7_debug_family_var_map[18];
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_p2;
  real_T c7_d0;
  real_T c7_p0;
  real_T c7_p1;
  real_T c7_nargin = 4.0;
  real_T c7_nargout = 6.0;
  real_T c7_dca;
  real_T c7_dcb;
  real_T c7_dcc;
  real_T c7_pa;
  real_T c7_pb;
  real_T c7_pc;
  real_T c7_a;
  real_T c7_b_a;
  real_T *c7_b_s1;
  real_T *c7_b_dc1;
  real_T *c7_b_s2;
  real_T *c7_b_dc2;
  real_T *c7_b_dca;
  real_T *c7_b_dcb;
  real_T *c7_b_dcc;
  real_T *c7_b_pa;
  real_T *c7_b_pb;
  real_T *c7_b_pc;
  c7_b_pc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_b_pb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_b_pa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_b_dcc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_b_dcb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_b_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_b_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_dca = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *c7_b_s1;
  c7_b_hoistedGlobal = *c7_b_dc1;
  c7_c_hoistedGlobal = *c7_b_s2;
  c7_d_hoistedGlobal = *c7_b_dc2;
  c7_s1 = c7_hoistedGlobal;
  c7_dc1 = c7_b_hoistedGlobal;
  c7_s2 = c7_c_hoistedGlobal;
  c7_dc2 = c7_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c7_d1, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_d2, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_p2, 2U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_d0, 3U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_p0, 4U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_p1, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 6U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_s1, 8U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_dc1, 9U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_s2, 10U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_dc2, 11U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_dca, 12U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_dcb, 13U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_dcc, 14U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_pa, 15U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_pb, 16U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_pc, 17U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
  c7_a = c7_dc1;
  c7_d1 = c7_a * 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_b_a = c7_dc2;
  c7_d2 = c7_b_a * 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  c7_p2 = 1000.0 - c7_d2;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  c7_d0 = (1000.0 - c7_d1) - c7_d2;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_p0 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
  c7_p1 = c7_d0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
  c7_dca = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 19);
  c7_dcb = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
  c7_dcc = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
  switch ((int32_T)_SFD_INTEGER_CHECK("s1", c7_s1)) {
   case 1:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
    c7_pa = c7_d0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 26);
    if (CV_EML_IF(0, 1, 0, c7_s2 == 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
      c7_pb = c7_d0 + c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 28);
      c7_pc = 1000.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 30);
      c7_pb = 1000.0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 31);
      c7_pc = c7_d0 + c7_d1;
    }
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 34);
    c7_pc = 1000.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 35);
    if (CV_EML_IF(0, 1, 1, c7_s2 == 3.0)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 36);
      c7_dca = c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 37);
      c7_pa = c7_d0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 38);
      c7_pb = c7_d0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 40);
      c7_pa = c7_d0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 41);
      c7_dcb = c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 42);
      c7_pb = c7_d0;
    }
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 45);
    c7_pb = c7_d0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 46);
    if (CV_EML_IF(0, 1, 2, c7_s2 == 4.0)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 47);
      c7_pa = 1000.0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 48);
      c7_pc = c7_d0 + c7_d1;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 50);
      c7_pa = c7_d0 + c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 51);
      c7_pc = 1000.0;
    }
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 54);
    c7_pa = 1000.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 55);
    if (CV_EML_IF(0, 1, 3, c7_s2 == 5.0)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 56);
      c7_dcb = c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 57);
      c7_pb = c7_d0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 58);
      c7_pc = c7_d0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 60);
      c7_pb = c7_d0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 61);
      c7_dcc = c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 62);
      c7_pc = c7_d0;
    }
    break;

   case 5:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 65);
    c7_pc = c7_d0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 66);
    if (CV_EML_IF(0, 1, 4, c7_s2 == 6.0)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 67);
      c7_pa = c7_d0 + c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 68);
      c7_pb = 1000.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 70);
      c7_pa = 1000.0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 71);
      c7_pb = c7_d0 + c7_d1;
    }
    break;

   case 6:
    CV_EML_SWITCH(0, 1, 0, 6);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 74);
    c7_pb = 1000.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 75);
    if (CV_EML_IF(0, 1, 5, c7_s2 == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 76);
      c7_pa = c7_d0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 77);
      c7_dcc = c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 78);
      c7_pc = c7_d0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 80);
      c7_dca = c7_d1;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 81);
      c7_pa = c7_d0;
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 82);
      c7_pc = c7_d0;
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 85);
    c7_pa = 1000.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 86);
    c7_pb = 1000.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 87);
    c7_pc = 1000.0;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -87);
  sf_debug_symbol_scope_pop();
  *c7_b_dca = c7_dca;
  *c7_b_dcb = c7_dcb;
  *c7_b_dcc = c7_dcc;
  *c7_b_pa = c7_pa;
  *c7_b_pb = c7_pb;
  *c7_b_pc = c7_pc;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_testing_SVM(SFc7_testing_SVMInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_testing_SVMInstanceStruct *chartInstance;
  chartInstance = (SFc7_testing_SVMInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct *chartInstance,
  const mxArray *c7_pc, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_pc), &c7_thisId);
  sf_mex_destroy(&c7_pc);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_pc;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_testing_SVMInstanceStruct *chartInstance;
  chartInstance = (SFc7_testing_SVMInstanceStruct *)chartInstanceVoid;
  c7_pc = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_pc), &c7_thisId);
  sf_mex_destroy(&c7_pc);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_testing_SVM_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[1];
  c7_ResolvedFunctionInfo (*c7_b_info)[1];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i0;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_b_info = (c7_ResolvedFunctionInfo (*)[1])c7_info;
  (*c7_b_info)[0].context = "";
  (*c7_b_info)[0].name = "mtimes";
  (*c7_b_info)[0].dominantType = "double";
  (*c7_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[0].fileTimeLo = 1289541292U;
  (*c7_b_info)[0].fileTimeHi = 0U;
  (*c7_b_info)[0].mFileTimeLo = 0U;
  (*c7_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c7_i0 = 0; c7_i0 < 1; c7_i0++) {
    c7_r0 = &c7_info[c7_i0];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i0);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i0);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_testing_SVMInstanceStruct *chartInstance;
  chartInstance = (SFc7_testing_SVMInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_c_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i1;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i1, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_testing_SVMInstanceStruct *chartInstance;
  chartInstance = (SFc7_testing_SVMInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_d_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_testing_SVM, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_testing_SVM), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_testing_SVM);
  return c7_y;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_testing_SVMInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_testing_SVMInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_testing_SVM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(59730116U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3695933208U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1082639210U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(497431498U);
}

mxArray *sf_c7_testing_SVM_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fatWlAsAJNdSygT739cfwD");
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

static const mxArray *sf_get_sim_state_info_c7_testing_SVM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"dca\",},{M[1],M[9],T\"dcb\",},{M[1],M[10],T\"dcc\",},{M[1],M[11],T\"pa\",},{M[1],M[12],T\"pb\",},{M[1],M[13],T\"pc\",},{M[8],M[0],T\"is_active_c7_testing_SVM\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_testing_SVM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_testing_SVMInstanceStruct *chartInstance;
    chartInstance = (SFc7_testing_SVMInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_testing_SVMMachineNumber_,
           7,
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
          init_script_number_translation(_testing_SVMMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_testing_SVMMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_testing_SVMMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"s1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dca");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dc1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"s2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dc2");
          _SFD_SET_DATA_PROPS(5,2,0,1,"dcb");
          _SFD_SET_DATA_PROPS(6,2,0,1,"dcc");
          _SFD_SET_DATA_PROPS(7,2,0,1,"pa");
          _SFD_SET_DATA_PROPS(8,2,0,1,"pb");
          _SFD_SET_DATA_PROPS(9,2,0,1,"pc");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1765);
        _SFD_CV_INIT_EML_IF(0,1,0,627,636,692,755);
        _SFD_CV_INIT_EML_IF(0,1,1,794,803,876,956);
        _SFD_CV_INIT_EML_IF(0,1,2,993,1002,1058,1120);
        _SFD_CV_INIT_EML_IF(0,1,3,1159,1170,1243,1323);
        _SFD_CV_INIT_EML_IF(0,1,4,1360,1369,1425,1488);
        _SFD_CV_INIT_EML_IF(0,1,5,1525,1534,1607,1687);

        {
          static int caseStart[] = { 1692, 595, 760, 961, 1125, 1328, 1493 };

          static int caseExprEnd[] = { 1701, 601, 766, 967, 1131, 1334, 1499 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,575,585,1760,7,&(caseStart[0]),
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
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          real_T *c7_s1;
          real_T *c7_dca;
          real_T *c7_dc1;
          real_T *c7_s2;
          real_T *c7_dc2;
          real_T *c7_dcb;
          real_T *c7_dcc;
          real_T *c7_pa;
          real_T *c7_pb;
          real_T *c7_pc;
          c7_pc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c7_pb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c7_pa = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c7_dcc = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c7_dcb = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c7_dc2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c7_s2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c7_dc1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c7_dca = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_s1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_s1);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_dca);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_dc1);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_s2);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_dc2);
          _SFD_SET_DATA_VALUE_PTR(5U, c7_dcb);
          _SFD_SET_DATA_VALUE_PTR(6U, c7_dcc);
          _SFD_SET_DATA_VALUE_PTR(7U, c7_pa);
          _SFD_SET_DATA_VALUE_PTR(8U, c7_pb);
          _SFD_SET_DATA_VALUE_PTR(9U, c7_pc);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_testing_SVMMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "wdXMH1fsqNJQac2vO5jxnG";
}

static void sf_opaque_initialize_c7_testing_SVM(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_testing_SVMInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*)
    chartInstanceVar);
  initialize_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_testing_SVM(void *chartInstanceVar)
{
  enable_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_testing_SVM(void *chartInstanceVar)
{
  disable_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_testing_SVM(void *chartInstanceVar)
{
  sf_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_testing_SVM(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_testing_SVM
    ((SFc7_testing_SVMInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_testing_SVM();/* state var info */
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

extern void sf_internal_set_sim_state_c7_testing_SVM(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_testing_SVM();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_testing_SVM(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_testing_SVM(S);
}

static void sf_opaque_set_sim_state_c7_testing_SVM(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c7_testing_SVM(S, st);
}

static void sf_opaque_terminate_c7_testing_SVM(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_testing_SVMInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_testing_SVM_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_testing_SVM((SFc7_testing_SVMInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_testing_SVM(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_testing_SVM((SFc7_testing_SVMInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_testing_SVM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testing_SVM_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,6);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3989301573U));
  ssSetChecksum1(S,(2757527393U));
  ssSetChecksum2(S,(1538540609U));
  ssSetChecksum3(S,(3086722779U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_testing_SVM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_testing_SVM(SimStruct *S)
{
  SFc7_testing_SVMInstanceStruct *chartInstance;
  chartInstance = (SFc7_testing_SVMInstanceStruct *)malloc(sizeof
    (SFc7_testing_SVMInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_testing_SVMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_testing_SVM;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_testing_SVM;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_testing_SVM;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_testing_SVM;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_testing_SVM;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_testing_SVM;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_testing_SVM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_testing_SVM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_testing_SVM;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_testing_SVM;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_testing_SVM;
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

void c7_testing_SVM_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_testing_SVM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_testing_SVM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_testing_SVM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_testing_SVM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
