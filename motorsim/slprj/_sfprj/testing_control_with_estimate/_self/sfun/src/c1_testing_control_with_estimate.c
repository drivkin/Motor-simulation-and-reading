/* Include files */

#include "blascompat32.h"
#include "testing_control_with_estimate_sfun.h"
#include "c1_testing_control_with_estimate.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testing_control_with_estimate_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[13] = { "L", "R", "Kt", "Ke", "Ides",
  "bemf", "ZL", "nargin", "nargout", "Tdes", "w", "Vd", "Vq" };

/* Function Declarations */
static void initialize_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void initialize_params_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void enable_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void disable_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void set_sim_state_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void sf_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void initSimStructsc1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_Vq, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_testing_control_with_estimate, const char_T
   *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_testing_control_with_estimate = 0U;
}

static void initialize_params_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
}

static void enable_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_Vd;
  real_T *c1_Vq;
  c1_Vq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Vd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_Vd;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_Vq;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal =
    chartInstance->c1_is_active_c1_testing_control_with_estimate;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Vd;
  real_T *c1_Vq;
  c1_Vq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Vd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Vd = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "Vd");
  *c1_Vq = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "Vq");
  chartInstance->c1_is_active_c1_testing_control_with_estimate =
    c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "is_active_c1_testing_control_with_estimate");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_testing_control_with_estimate(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
}

static void sf_c1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_Tdes;
  real_T c1_w;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_L;
  real_T c1_R;
  real_T c1_Kt;
  real_T c1_Ke;
  real_T c1_Ides;
  real_T c1_bemf;
  real_T c1_ZL;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 2.0;
  real_T c1_Vd;
  real_T c1_Vq;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b_A;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b;
  real_T c1_b_b;
  real_T c1_a;
  real_T c1_y;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_b_y;
  real_T c1_d_a;
  real_T *c1_b_Vq;
  real_T *c1_b_Vd;
  real_T *c1_b_w;
  real_T *c1_b_Tdes;
  c1_b_Vq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_Vd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Tdes = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_Tdes, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Vd, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_w, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Vq, 3U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_Tdes;
  c1_b_hoistedGlobal = *c1_b_w;
  c1_Tdes = c1_hoistedGlobal;
  c1_w = c1_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_L, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_R, 1U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Kt, 2U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Ke, 3U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_Ides, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_bemf, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ZL, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_Tdes, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_w, 10U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_Vd, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Vq, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_A = c1_w;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_w = c1_b_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_L = 0.0019399999999999999;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_R = 24.421916386721168;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_Kt = 0.015675059808498339;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_Ke = 0.00905;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_b_A = c1_Tdes;
  c1_c_x = c1_b_A;
  c1_d_x = c1_c_x;
  c1_Ides = c1_d_x / 0.015675059808498339;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_b = c1_w;
  c1_bemf = 0.00905 * c1_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_b_b = c1_w;
  c1_ZL = 0.0019399999999999999 * c1_b_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_a = c1_Ides;
  c1_y = c1_a * 24.421916386721168;
  c1_b_a = c1_bemf + c1_y;
  c1_Vq = c1_b_a * 1.7320508075688772;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_c_a = -c1_ZL;
  c1_c_b = c1_Ides;
  c1_b_y = c1_c_a * c1_c_b;
  c1_d_a = c1_b_y;
  c1_Vd = c1_d_a * 1.7320508075688772;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -27);
  sf_debug_symbol_scope_pop();
  *c1_b_Vd = c1_Vd;
  *c1_b_Vq = c1_Vq;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_testing_control_with_estimateMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_testing_control_with_estimate
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testing_control_with_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc1_testing_control_with_estimateInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_Vq, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Vq), &c1_thisId);
  sf_mex_destroy(&c1_Vq);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Vq;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_testing_control_with_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc1_testing_control_with_estimateInstanceStruct *)
    chartInstanceVoid;
  c1_Vq = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Vq), &c1_thisId);
  sf_mex_destroy(&c1_Vq);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray
  *sf_c1_testing_control_with_estimate_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[12];
  c1_ResolvedFunctionInfo (*c1_b_info)[12];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[12])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mrdivide";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[0].fileTimeLo = 1325145738U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 1319751566U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].name = "rdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[1].fileTimeLo = 1286840444U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].name = "eml_div";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[2].fileTimeLo = 1313369410U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "mpower";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c1_b_info)[3].fileTimeLo = 1286840442U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c1_b_info)[4].name = "power";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[4].fileTimeLo = 1307672840U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[5].name = "eml_scalar_eg";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[5].fileTimeLo = 1286840396U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[6].name = "eml_scalexp_alloc";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c1_b_info)[6].fileTimeLo = 1286840396U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  (*c1_b_info)[7].name = "eml_scalar_floor";
  (*c1_b_info)[7].dominantType = "double";
  (*c1_b_info)[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c1_b_info)[7].fileTimeLo = 1286840326U;
  (*c1_b_info)[7].fileTimeHi = 0U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  (*c1_b_info)[8].context = "";
  (*c1_b_info)[8].name = "mtimes";
  (*c1_b_info)[8].dominantType = "double";
  (*c1_b_info)[8].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[8].fileTimeLo = 1289541292U;
  (*c1_b_info)[8].fileTimeHi = 0U;
  (*c1_b_info)[8].mFileTimeLo = 0U;
  (*c1_b_info)[8].mFileTimeHi = 0U;
  (*c1_b_info)[9].context = "";
  (*c1_b_info)[9].name = "sqrt";
  (*c1_b_info)[9].dominantType = "double";
  (*c1_b_info)[9].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c1_b_info)[9].fileTimeLo = 1286840352U;
  (*c1_b_info)[9].fileTimeHi = 0U;
  (*c1_b_info)[9].mFileTimeLo = 0U;
  (*c1_b_info)[9].mFileTimeHi = 0U;
  (*c1_b_info)[10].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c1_b_info)[10].name = "eml_error";
  (*c1_b_info)[10].dominantType = "char";
  (*c1_b_info)[10].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c1_b_info)[10].fileTimeLo = 1305339600U;
  (*c1_b_info)[10].fileTimeHi = 0U;
  (*c1_b_info)[10].mFileTimeLo = 0U;
  (*c1_b_info)[10].mFileTimeHi = 0U;
  (*c1_b_info)[11].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c1_b_info)[11].name = "eml_scalar_sqrt";
  (*c1_b_info)[11].dominantType = "double";
  (*c1_b_info)[11].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c1_b_info)[11].fileTimeLo = 1286840338U;
  (*c1_b_info)[11].fileTimeHi = 0U;
  (*c1_b_info)[11].mFileTimeLo = 0U;
  (*c1_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12), FALSE);
  for (c1_i0 = 0; c1_i0 < 12; c1_i0++) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testing_control_with_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc1_testing_control_with_estimateInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_testing_control_with_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc1_testing_control_with_estimateInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_testing_control_with_estimate, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_testing_control_with_estimate), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_testing_control_with_estimate);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_testing_control_with_estimateInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_testing_control_with_estimate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4283387691U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2306185436U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(360744967U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(203268949U);
}

mxArray *sf_c1_testing_control_with_estimate_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("viomeANcBPS6dCBnnRUOBD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_testing_control_with_estimate
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Vd\",},{M[1],M[7],T\"Vq\",},{M[8],M[0],T\"is_active_c1_testing_control_with_estimate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_testing_control_with_estimate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_testing_control_with_estimateInstanceStruct *chartInstance;
    chartInstance = (SFc1_testing_control_with_estimateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_testing_control_with_estimateMachineNumber_,
           1,
           1,
           1,
           4,
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
            (_testing_control_with_estimateMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_testing_control_with_estimateMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_testing_control_with_estimateMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Tdes");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Vd");
          _SFD_SET_DATA_PROPS(2,1,1,0,"w");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Vq");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,583);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_Tdes;
          real_T *c1_Vd;
          real_T *c1_w;
          real_T *c1_Vq;
          c1_Vq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_Vd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Tdes = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_Tdes);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_Vd);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_w);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Vq);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_testing_control_with_estimateMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "uWuL7AUOlprJBYHwj2LI1D";
}

static void sf_opaque_initialize_c1_testing_control_with_estimate(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_testing_control_with_estimateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
  initialize_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_testing_control_with_estimate(void
  *chartInstanceVar)
{
  enable_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_testing_control_with_estimate(void
  *chartInstanceVar)
{
  disable_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_testing_control_with_estimate(void
  *chartInstanceVar)
{
  sf_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_testing_control_with_estimate
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_testing_control_with_estimate();/* state var info */
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

extern void sf_internal_set_sim_state_c1_testing_control_with_estimate(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_testing_control_with_estimate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_testing_control_with_estimate
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_testing_control_with_estimate(S);
}

static void sf_opaque_set_sim_state_c1_testing_control_with_estimate(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_testing_control_with_estimate(S, st);
}

static void sf_opaque_terminate_c1_testing_control_with_estimate(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_testing_control_with_estimateInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_testing_control_with_estimate
      ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_testing_control_with_estimate_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_testing_control_with_estimate
    ((SFc1_testing_control_with_estimateInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_testing_control_with_estimate(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_testing_control_with_estimate
      ((SFc1_testing_control_with_estimateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_testing_control_with_estimate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testing_control_with_estimate_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2166216647U));
  ssSetChecksum1(S,(1650704070U));
  ssSetChecksum2(S,(2125331085U));
  ssSetChecksum3(S,(653506472U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_testing_control_with_estimate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_testing_control_with_estimate(SimStruct *S)
{
  SFc1_testing_control_with_estimateInstanceStruct *chartInstance;
  chartInstance = (SFc1_testing_control_with_estimateInstanceStruct *)malloc
    (sizeof(SFc1_testing_control_with_estimateInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_testing_control_with_estimateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_testing_control_with_estimate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_testing_control_with_estimate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_testing_control_with_estimate;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_testing_control_with_estimate;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_testing_control_with_estimate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_testing_control_with_estimate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_testing_control_with_estimate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_testing_control_with_estimate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_testing_control_with_estimate;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_testing_control_with_estimate;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_testing_control_with_estimate;
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

void c1_testing_control_with_estimate_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_testing_control_with_estimate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_testing_control_with_estimate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_testing_control_with_estimate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_testing_control_with_estimate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
