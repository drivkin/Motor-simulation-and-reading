/* Include files */

#include "motor_control_with_homebrew_SVPWM_sfun.h"
#include "c1_motor_control_with_homebrew_SVPWM.h"
#include "c2_motor_control_with_homebrew_SVPWM.h"
#include "c5_motor_control_with_homebrew_SVPWM.h"
#include "c6_motor_control_with_homebrew_SVPWM.h"
#include "c8_motor_control_with_homebrew_SVPWM.h"
#include "c9_motor_control_with_homebrew_SVPWM.h"
#include "c10_motor_control_with_homebrew_SVPWM.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _motor_control_with_homebrew_SVPWMMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void motor_control_with_homebrew_SVPWM_initializer(void)
{
}

void motor_control_with_homebrew_SVPWM_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_motor_control_with_homebrew_SVPWM_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_motor_control_with_homebrew_SVPWM_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_motor_control_with_homebrew_SVPWM_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1526740792U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(631682955U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1363003466U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3705030014U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1713673360U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2176666504U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3494854409U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2548504416U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c1_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c2_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c5_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c6_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c8_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c9_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_motor_control_with_homebrew_SVPWM_get_check_sum
            (mxArray *plhs[]);
          sf_c10_motor_control_with_homebrew_SVPWM_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1152073008U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2034906000U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1357906625U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1475857395U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_motor_control_with_homebrew_SVPWM_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "VgypGoBsFN5GpnLwjqYYGH") == 0) {
          extern mxArray
            *sf_c1_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "4a5oG7LwFaxQG4sngRR1FF") == 0) {
          extern mxArray
            *sf_c2_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "dxN03vC2tBjZX04T0oOSrC") == 0) {
          extern mxArray
            *sf_c5_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "3CKMLY9h0CLViHcQ41angF") == 0) {
          extern mxArray
            *sf_c6_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c6_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "EMX3ib0abfHmZP7uaBY1ZH") == 0) {
          extern mxArray
            *sf_c8_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c8_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "fatWlAsAJNdSygT739cfwD") == 0) {
          extern mxArray
            *sf_c9_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c9_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "5LMTnlCeCvRNUd4vMXsdIG") == 0) {
          extern mxArray
            *sf_c10_motor_control_with_homebrew_SVPWM_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c10_motor_control_with_homebrew_SVPWM_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_motor_control_with_homebrew_SVPWM_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void motor_control_with_homebrew_SVPWM_debug_initialize(void)
{
  _motor_control_with_homebrew_SVPWMMachineNumber_ = sf_debug_initialize_machine
    ("motor_control_with_homebrew_SVPWM","sfun",0,7,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_motor_control_with_homebrew_SVPWMMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_motor_control_with_homebrew_SVPWMMachineNumber_,0);
}

void motor_control_with_homebrew_SVPWM_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_motor_control_with_homebrew_SVPWM_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "motor_control_with_homebrew_SVPWM", "motor_control_with_homebrew_SVPWM");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_motor_control_with_homebrew_SVPWM_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
