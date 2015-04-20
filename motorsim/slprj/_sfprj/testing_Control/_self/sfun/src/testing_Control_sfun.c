/* Include files */

#include "testing_Control_sfun.h"
#include "c1_testing_Control.h"
#include "c2_testing_Control.h"
#include "c5_testing_Control.h"
#include "c6_testing_Control.h"
#include "c8_testing_Control.h"
#include "c9_testing_Control.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _testing_ControlMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void testing_Control_initializer(void)
{
}

void testing_Control_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_testing_Control_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_testing_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_testing_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_testing_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_testing_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_testing_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_testing_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_testing_Control_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3881922837U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3139523138U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3445156951U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3635042845U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3445541179U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2184280447U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1820129773U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(380690334U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_testing_Control_get_check_sum(mxArray *plhs[]);
          sf_c1_testing_Control_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_testing_Control_get_check_sum(mxArray *plhs[]);
          sf_c2_testing_Control_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_testing_Control_get_check_sum(mxArray *plhs[]);
          sf_c5_testing_Control_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_testing_Control_get_check_sum(mxArray *plhs[]);
          sf_c6_testing_Control_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_testing_Control_get_check_sum(mxArray *plhs[]);
          sf_c8_testing_Control_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_testing_Control_get_check_sum(mxArray *plhs[]);
          sf_c9_testing_Control_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(23490113U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1330822336U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(603629032U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3530902911U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_testing_Control_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "DcFacaP2q4yaV1a82mv7kB") == 0) {
          extern mxArray *sf_c1_testing_Control_get_autoinheritance_info(void);
          plhs[0] = sf_c1_testing_Control_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "4a5oG7LwFaxQG4sngRR1FF") == 0) {
          extern mxArray *sf_c2_testing_Control_get_autoinheritance_info(void);
          plhs[0] = sf_c2_testing_Control_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "dxN03vC2tBjZX04T0oOSrC") == 0) {
          extern mxArray *sf_c5_testing_Control_get_autoinheritance_info(void);
          plhs[0] = sf_c5_testing_Control_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "3CKMLY9h0CLViHcQ41angF") == 0) {
          extern mxArray *sf_c6_testing_Control_get_autoinheritance_info(void);
          plhs[0] = sf_c6_testing_Control_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "EMX3ib0abfHmZP7uaBY1ZH") == 0) {
          extern mxArray *sf_c8_testing_Control_get_autoinheritance_info(void);
          plhs[0] = sf_c8_testing_Control_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "20tQ8Vgu2aSDbBrlbe3cqD") == 0) {
          extern mxArray *sf_c9_testing_Control_get_autoinheritance_info(void);
          plhs[0] = sf_c9_testing_Control_get_autoinheritance_info();
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

unsigned int sf_testing_Control_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_testing_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_testing_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_testing_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_testing_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_testing_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_testing_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_testing_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_testing_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_testing_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_testing_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_testing_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_testing_Control_get_eml_resolved_functions_info();
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

void testing_Control_debug_initialize(void)
{
  _testing_ControlMachineNumber_ = sf_debug_initialize_machine("testing_Control",
    "sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(_testing_ControlMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_testing_ControlMachineNumber_,0);
}

void testing_Control_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_testing_Control_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("testing_Control",
      "testing_Control");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_testing_Control_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
