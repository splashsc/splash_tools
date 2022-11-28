char *__fastcall read_ipsec_file(char *a1, int a2)
{
  FILE *v3; // $s2
  char *v4; // $s4
  int v5; // $a0
  char *v6; // $v1
  char *v7; // $v1
  int v8; // $v0
  _BYTE *v9; // $a0
  int v10; // $v0
  unsigned __int8 v11; // $v0
  int v12; // $v0
  bool v13; // dc
  int v14; // $v0
  char v16[1024]; // [sp+20h] [-400h] BYREF

  memset(v16, 0, sizeof(v16));
  v3 = fopen("/etc/racoon/ipsec.log", "r");
  v4 = a1;
  if ( v3 )
  {
LABEL_2:
    while ( fgets(v16, 1023, v3) && a2 >= 3000 )
    {
      v5 = 0;
      if ( !v16[0] )
        goto LABEL_2;
      v6 = v16;
      if ( v16[0] != 58 )
        goto LABEL_6;
      while ( 1 )
      {
        if ( ++v5 == 3 )
        {
          *v6 = 0;
LABEL_6:
          ++v6;
          goto LABEL_7;
        }
        ++v6;
        if ( v5 == 4 )
          break;
LABEL_7:
        if ( !*v6 )
          goto LABEL_2;
        if ( *v6 != 58 )
          goto LABEL_6;
      }
      v7 = v6 - 1;
      v8 = v7[1];
      *v7 = 0;
      v9 = v7 + 1;
      if ( v8 )
      {
        while ( 2 )
        {
          v11 = v8 - 34;
          while ( v11 < 0x1Bu && ((0x4000021u >> v11) & 1) != 0 )
          {
            *v9++ = 32;
            v12 = (char)*v9;
            v13 = v12 != 0;
            v11 = v12 - 34;
            if ( !v13 )
              goto LABEL_20;
          }
          v10 = (char)*v9;
          if ( v10 != 10 && v10 != 13 )
          {
            LOBYTE(v8) = *++v9;
            if ( *v9 )
              continue;
LABEL_20:
            if ( !v7[1] )
              goto LABEL_2;
            goto LABEL_21;
          }
          break;
        }
        *v9 = 0;
        if ( !v7[1] )
          goto LABEL_2;
LABEL_21:
        v14 = snprintf(v4, a2, "\"%s <%s\",", v7 + 1, v16);
        if ( v14 >= a2 )
          v14 = a2 - 1;
        a2 -= v14;
        v4 += v14;
      }
    }
    fclose(v3);
  }
  return (char *)(v4 - a1);
}
// 4542D8: conditional instruction was optimized away because of '$s2.4!=0'

