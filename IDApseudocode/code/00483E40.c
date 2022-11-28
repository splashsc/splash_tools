ssize_t __fastcall flash_Kernel_write(char *a1, int a2, int a3, int a4, unsigned int a5)
{
  unsigned int v6; // $s1
  int v7; // $v0
  int v9; // $v0
  int v10; // $s3
  size_t v11; // $a2
  ssize_t v12; // $s0
  __off_t v13; // $a1
  char *v14; // $v0
  char *v15; // $s2
  int v16; // $s0
  size_t v17; // $a0
  int v18; // $s7
  __off_t v19; // $a1
  ssize_t result; // $v0
  int v21; // $v0
  FILE *v22; // $a3
  const char *v23; // $a0
  char v24[8]; // [sp+20h] [-30h] BYREF
  unsigned int v25; // [sp+28h] [-28h]
  size_t nbytes; // [sp+2Ch] [-24h]
  int v27; // [sp+40h] [-10h] BYREF
  size_t v28; // [sp+44h] [-Ch]
  unsigned int request; // [sp+48h] [-8h]
  char *v30; // [sp+4Ch] [-4h]

  v6 = a5;
  v7 = mtd_open("Kernel", 16402);
  if ( v7 < 0 )
  {
    fwrite("Could not open mtd device\n", 1u, 0x1Au, stderr);
    result = -1;
  }
  else
  {
    v10 = v7;
    v9 = ioctl(v7, 0x40204D01u, v24);
    v11 = 30;
    if ( v9 )
    {
      v22 = stderr;
      v23 = "Could not get mtd device info\n";
LABEL_21:
      fwrite(v23, 1u, v11, v22);
      close(v10);
      return -1;
    }
    if ( v25 >= a5 )
    {
      v12 = 0;
      if ( !a5 )
      {
LABEL_15:
        close(v10);
        return v12;
      }
      request = -2146939646;
      while ( 1 )
      {
        while ( ((nbytes - 1) & v6) != 0 || v6 < nbytes )
        {
          _mem_malloc(nbytes, "flash_Kernel_write", 1080);
          v15 = v14;
          v30 = "1\"";
          if ( !v14 )
          {
            v22 = stderr;
            v11 = 18;
            v23 = "Not enough memory\n";
            goto LABEL_21;
          }
          v16 = -nbytes & a3;
          lseek(v10, v13, v16);
          if ( read(v10, v15, nbytes) == -1 )
          {
            fwrite("Reading from mtd failed\n", 1u, 0x18u, stderr);
            close(v10);
            _mem_free(v15);
            return -1;
          }
          v17 = (nbytes - 1) & a3;
          v18 = nbytes - v17;
          if ( v6 < nbytes - v17 )
            v18 = v6;
          memcpy(&v15[v17], a1, v18);
          v27 = v16;
          v28 = nbytes;
          if ( ioctl(v10, request, &v27) < 0 )
          {
            fwrite("Erasing mtd failed\n", 1u, 0x13u, stderr);
            close(v10);
LABEL_24:
            _mem_free(v15);
            return -1;
          }
          lseek(v10, v19, v16);
          v12 = write(v10, v15, nbytes);
          if ( v12 == -1 )
          {
            fwrite("Writing to mtd failed\n", 1u, 0x16u, stderr);
            close(v10);
            goto LABEL_24;
          }
          v6 -= v18;
          _mem_free(v15);
          a1 += v18;
          a3 += v18;
          if ( !v6 )
            goto LABEL_15;
        }
        v27 = a3;
        v28 = nbytes;
        v21 = ioctl(v10, request, &v27);
        v11 = 19;
        if ( v21 < 0 )
          break;
        v12 = write(v10, a1, nbytes);
        v11 = 22;
        if ( v12 == -1 )
        {
          v22 = stderr;
          v23 = "Writing to mtd failed\n";
          goto LABEL_21;
        }
        v6 -= nbytes;
        a1 += nbytes;
        a3 += nbytes;
        if ( !v6 )
          goto LABEL_15;
      }
      v22 = stderr;
      v23 = "Erasing mtd failed\n";
      goto LABEL_21;
    }
    fprintf(stderr, "Too many bytes: %zu > %d bytes\n", a5, v25);
    close(v10);
    result = -2;
  }
  return result;
}
// 483F38: variable 'v14' is possibly undefined
// 483F64: variable 'v13' is possibly undefined
// 484008: variable 'v19' is possibly undefined
// 6A8684: using guessed type int __fastcall mtd_open(_DWORD, _DWORD);

