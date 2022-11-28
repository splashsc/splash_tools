int __fastcall _httpd_parm_do(char *a1)
{
  int result; // $v0
  char *v2; // $a0
  int v3; // $a2
  unsigned int v4; // $v1
  int v5; // $t1
  unsigned int v6; // $a3
  _BOOL4 v7; // $t3
  unsigned int v8; // $t4
  unsigned int v9; // $v0
  char v10; // $v0
  unsigned int v11; // $v1
  int v12; // $v1
  _BYTE *v13; // $v0

  result = *a1;
  v2 = a1 + 1;
  if ( result )
  {
    while ( result != 37 )
    {
LABEL_3:
      result = *v2;
LABEL_4:
      ++v2;
      if ( !result )
        return result;
    }
    result = *v2;
    v3 = (unsigned __int8)*v2;
    v4 = (unsigned __int8)(v3 - 48);
    if ( v4 < 0xA )
    {
      v5 = (unsigned __int8)v2[1];
      v6 = (unsigned __int8)(v5 - 48);
      v7 = v6 < 0xA;
      v8 = v5 & 0xFFFFFFDF;
      if ( v6 < 0xA )
      {
        v10 = v6 + 16 * v4;
        goto LABEL_15;
      }
    }
    else
    {
      if ( (v3 & 0xFFFFFFDF) - 65 >= 6 )
        goto LABEL_4;
      v5 = (unsigned __int8)v2[1];
      v6 = (unsigned __int8)(v5 - 48);
      v7 = v6 < 0xA;
      v8 = v5 & 0xFFFFFFDF;
      if ( v6 < 0xA )
      {
        v9 = v3 - 97;
        goto LABEL_10;
      }
    }
    if ( v8 - 65 >= 6 )
      goto LABEL_4;
    v9 = v3 - 97;
    if ( v4 < 0xA )
    {
      v10 = 16 * v4;
      v11 = v5 - 97;
      goto LABEL_22;
    }
LABEL_10:
    if ( v9 < 6 )
    {
      v10 = 16 * (v3 - 87);
    }
    else
    {
      v10 = 0;
      if ( (unsigned int)(v3 - 65) < 6 )
        v10 = 16 * (v3 - 55);
    }
    v11 = v5 - 97;
    if ( v7 )
    {
      v10 += v6;
LABEL_15:
      v12 = v2[2];
      *(v2 - 1) = v10;
      v13 = v2;
      if ( v12 )
      {
        do
        {
          *v13++ = v12;
          LOBYTE(v12) = v13[2];
        }
        while ( (_BYTE)v12 );
      }
      *v13 = 0;
      goto LABEL_3;
    }
LABEL_22:
    if ( v11 < 6 )
    {
      v10 += v5 - 87;
    }
    else if ( (unsigned int)(v5 - 65) < 6 )
    {
      v10 += v5 - 55;
    }
    goto LABEL_15;
  }
  return result;
}

