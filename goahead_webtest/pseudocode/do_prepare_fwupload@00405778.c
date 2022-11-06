
void do_prepare_fwupload(void)

{
  (*(code *)PTR_exe_ExternalCall_00430a48)(0x400);
                    /* WARNING: Could not recover jumptable at 0x004057b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_dxmlSetInt_00430968)(1,"/runtime/fwupgradeinfo/state");
  return;
}

