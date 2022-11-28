int __fastcall flash_Kernel_read(void *a1, int a2, int a3, int a4, size_t a5)
{
  int v7; // $v0
  int v8; // $s0
  int v9; // $v0
  __off_t v10; // $a1
  int v11; // $s1
  ssize_t v12; // $s0
  int result; // $v0
  char v14[8]; // [sp+20h] [-24h] BYREF
  unsigned int v15; // [sp+28h] [-1Ch]
  int v16; // [sp+2Ch] [-18h]

  v7 = mtd_open("Kernel", 0);
  if ( v7 < 0 )
  {
    fwrite("Could not open mtd device\n", 1u, 0x1Au, stderr);
    return -1;
  }
  v8 = v7;
  if ( ioctl(v7, 0x40204D01u, v14) )
  {
    fwrite("Could not get mtd device info\n", 1, 30, stderr);
    goto LABEL_9;
  }
  if ( v15 < a5 )
  {
    fprintf(stderr, "Too many bytes - %zu > %d bytes\n", a5, v16);
LABEL_9:
    close(v8);
    return -1;
  }
  close(v8);
  v9 = mtd_open("Kernel", 0);
  v11 = v9;
  if ( v9 < 0 )
  {
    fwrite("Could not open mtd block device\n", 1u, 0x20u, stderr);
    result = -1;
  }
  else
  {
    lseek(v9, v10, a3);
    v12 = read(v11, a1, a5);
    if ( v12 == -1 )
    {
      fwrite("Reading from mtd failed\n", 1u, 0x18u, stderr);
      close(v11);
      result = -1;
    }
    else
    {
      close(v11);
      result = v12;
    }
  }
  return result;
}
// 483CEC: variable 'v10' is possibly undefined
// 6A8684: using guessed type int __fastcall mtd_open(_DWORD, _DWORD);

