ssize_t __fastcall flash_art_write(char *a1, int a2, int a3, int a4, unsigned int a5, char *s)
{
  unsigned int v7; // $s1
  int v8; // $v0
  int v10; // $s3
  ssize_t v11; // $s0
  __off_t v12; // $a1
  char *v13; // $v0
  char *v14; // $s2
  int v15; // $s0
  size_t v16; // $a0
  int v17; // $fp
  __off_t v18; // $a1
  ssize_t result; // $v0
  char v20[8]; // [sp+20h] [-30h] BYREF
  unsigned int v21; // [sp+28h] [-28h]
  size_t nbytes; // [sp+2Ch] [-24h]
  int v23; // [sp+40h] [-10h] BYREF
  size_t v24; // [sp+44h] [-Ch]
  unsigned int request; // [sp+48h] [-8h]
  char *v26; // [sp+4Ch] [-4h]

  v7 = a5;
  v8 = mtd_open("Factory", 16402);
  if ( v8 < 0 )
  {
    fwrite("Could not open mtd device\n", 1u, 0x1Au, stderr);
    strcpy(s, "Could not open mtd device\n");
    qmemcpy(s, "Could not open m", 16);
    *((_DWORD *)s + 5) = *(_DWORD *)"evice\n";
    result = -1;
  }
  else
  {
    v10 = v8;
    if ( ioctl(v8, 0x40204D01u, v20) )
    {
      fwrite("Could not get mtd device info\n", 1u, 0x1Eu, stderr);
      strcpy(s, "Could not get mtd device info\n");
      qmemcpy(s, "Could not get mt", 16);
      close(v10);
      result = -1;
    }
    else if ( v21 < a5 )
    {
      fprintf(stderr, "Too many bytes: %d > %d bytes\n", a5, v21);
      sprintf(s, "Too many bytes: %d > %d bytes\n", a5, v21);
      close(v10);
      result = -1;
    }
    else
    {
      v11 = 0;
      if ( a5 )
      {
        request = -2146939646;
        while ( 1 )
        {
          while ( ((nbytes - 1) & v7) != 0 || v7 < nbytes )
          {
            _mem_malloc(nbytes, "flash_art_write", 1406);
            v14 = v13;
            v26 = "1\"";
            if ( !v13 )
            {
              fwrite("Not enough memory\n", 1u, 0x12u, stderr);
              strcpy(s, "Not enough memory\n");
              qmemcpy(s, "Not enough memor", 16);
              close(v10);
              return -1;
            }
            v15 = -nbytes & a3;
            lseek(v10, v12, v15);
            if ( read(v10, v14, nbytes) == -1 )
            {
              fwrite("Reading from mtd failed\n", 1u, 0x18u, stderr);
              strcpy(s, "Reading from mtd failed\n");
              qmemcpy(s, "Reading from mtd failed\n", 24);
              close(v10);
              _mem_free(v14);
              return -1;
            }
            v16 = (nbytes - 1) & a3;
            v17 = nbytes - v16;
            if ( v7 < nbytes - v16 )
              v17 = v7;
            memcpy(&v14[v16], a1, v17);
            v23 = v15;
            v24 = nbytes;
            if ( ioctl(v10, request, &v23) < 0 )
            {
              fwrite("Erasing mtd failed\n", 1u, 0x13u, stderr);
              strcpy(s, "Erasing mtd failed\n");
              strcpy(s, "Erasing mtd failed\n");
              close(v10);
LABEL_23:
              _mem_free(v14);
              return -1;
            }
            lseek(v10, v18, v15);
            v11 = write(v10, v14, nbytes);
            if ( v11 == -1 )
            {
              fwrite("Writing to mtd failed\n", 1u, 0x16u, stderr);
              close(v10);
              goto LABEL_23;
            }
            v7 -= v17;
            _mem_free(v14);
            a1 += v17;
            a3 += v17;
            if ( !v7 )
              goto LABEL_15;
          }
          v23 = a3;
          v24 = nbytes;
          if ( ioctl(v10, request, &v23) < 0 )
            break;
          v11 = write(v10, a1, nbytes);
          if ( v11 == -1 )
          {
            fwrite("Writing to mtd failed\n", 1u, 0x16u, stderr);
            strcpy(s, "Writing to mtd failed\n");
            qmemcpy(s, "Writing to mtd faile", 20);
            close(v10);
            return -1;
          }
          v7 -= nbytes;
          a1 += nbytes;
          a3 += nbytes;
          if ( !v7 )
            goto LABEL_15;
        }
        fwrite("Erasing mtd failed\n", 1u, 0x13u, stderr);
        strcpy(s, "Erasing mtd failed\n");
        strcpy(s, "Erasing mtd failed\n");
        close(v10);
        result = -1;
      }
      else
      {
LABEL_15:
        close(v10);
        result = v11;
      }
    }
  }
  return result;
}
// 485008: variable 'v13' is possibly undefined
// 485034: variable 'v12' is possibly undefined
// 4850D8: variable 'v18' is possibly undefined
// 6A8684: using guessed type int __fastcall mtd_open(_DWORD, _DWORD);

