char *__fastcall read_error_by_ipsec_file(char *a1, int a2)
{
  FILE *v3; // $s3
  char *v4; // $s5
  const char *v5; // $fp
  bool v6; // dc
  _BOOL4 v7; // $v0
  int v8; // $v1
  int v9; // $v0
  char *v10; // $s0
  char v11; // $v0
  char *v12; // $v1
  int v13; // $v0
  unsigned __int8 v14; // $v0
  int v15; // $v0
  int v16; // $v0
  char *v18; // $fp
  char v19[1024]; // [sp+20h] [-400h] BYREF

  memset(v19, 0, sizeof(v19));
  v3 = fopen("/etc/racoon/ipsec.log", "r");
  if ( !v3 )
    return 0;
  v4 = a1;
  v5 = 0;
LABEL_3:
  v6 = fgets(v19, 1023, v3) == 0;
  v7 = a2 < 3000;
  if ( v6 )
    goto LABEL_26;
  do
  {
    v8 = 0;
    if ( v7 )
      break;
    v9 = v19[0];
    v10 = v19;
    while ( v9 )
    {
      if ( v9 != 58 )
        goto LABEL_8;
      if ( ++v8 == 3 )
      {
        v9 = v10[1];
        v5 = v10 + 1;
        *v10 = 0;
        if ( v9 == 32 )
        {
          v18 = v10 + 2;
          do
            v9 = *v18++;
          while ( v9 == 32 );
          v5 = v18 - 1;
        }
        v10 = (char *)v5;
      }
      else
      {
        if ( v8 == 4 )
        {
          *v10++ = 0;
          break;
        }
LABEL_8:
        v9 = *++v10;
      }
    }
    if ( strcmp(v5, "ERROR") )
      goto LABEL_3;
    v11 = *v10;
    if ( !*v10 )
      goto LABEL_3;
    v12 = v10;
    while ( 2 )
    {
      v14 = v11 - 34;
      while ( v14 < 0x1Bu && ((0x4000021u >> v14) & 1) != 0 )
      {
        *v12++ = 32;
        v15 = *v12;
        v6 = v15 != 0;
        v14 = v15 - 34;
        if ( !v6 )
          goto LABEL_22;
      }
      v13 = *v12;
      if ( v13 != 10 && v13 != 13 )
      {
        v11 = *++v12;
        if ( *v12 )
          continue;
LABEL_22:
        if ( !*v10 )
          goto LABEL_3;
        goto LABEL_23;
      }
      break;
    }
    *v12 = 0;
    if ( !*v10 )
      goto LABEL_3;
LABEL_23:
    v16 = snprintf(v4, a2, "\"%s <%s\",", v10, v19);
    if ( v16 >= a2 )
      v16 = a2 - 1;
    a2 -= v16;
    v4 += v16;
    v6 = fgets(v19, 1023, v3) != 0;
    v7 = a2 < 3000;
  }
  while ( v6 );
LABEL_26:
  fclose(v3);
  return (char *)(v4 - a1);
}

