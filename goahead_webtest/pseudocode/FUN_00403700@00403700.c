
/* WARNING: Removing unreachable block (ram,0x00403754) */

void FUN_00403700(void)

{
  if (DAT_00430b00 == '\0') {
    if (PTR___deregister_frame_info_00430a30 != (undefined *)0x0) {
      (*(code *)PTR___deregister_frame_info_00430a30)(&DWORD_00420008);
    }
    DAT_00430b00 = '\x01';
  }
  return;
}

