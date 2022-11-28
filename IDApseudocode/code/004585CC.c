int __fastcall sub_4585CC(int a1)
{
  char *v1; // $s2
  char *v2; // $s3
  char *v3; // $s1
  char *v4; // $s0
  const char *v5; // $a0
  int v6; // $s5
  int v7; // $s0
  int v8; // $v0
  int v9; // $v0
  _DWORD *v10; // $fp
  int v11; // $s7
  int v12; // $s3
  int v13; // $s4
  const char *v14; // $s6
  int v15; // $s0
  int v16; // $v0
  char *v17; // $s0
  char *v18; // $v1
  const char *v19; // $v0
  int v20; // $t0
  int v21; // $a3
  int v22; // $a2
  int v23; // $a1
  int v25[64]; // [sp+20h] [-118h] BYREF
  int v26; // [sp+120h] [-18h]
  int v27; // [sp+124h] [-14h]
  char *v28; // [sp+128h] [-10h]
  char *v29; // [sp+12Ch] [-Ch]
  char *v30; // [sp+130h] [-8h]

  v1 = httpd_get_parm(a1, "fip");
  v2 = httpd_get_parm(a1, "dns");
  v3 = httpd_get_parm(a1, "prot");
  v4 = httpd_get_parm(a1, "inip");
  v26 = httpd_get_json_parm(a1, (int)"wans");
  if ( v1 )
    jhl_parm_set("qosFip", v1);
  if ( v2 )
    jhl_parm_set("qosDns", v2);
  if ( v3 )
    jhl_parm_set("qosProt", v3);
  if ( v4 )
    jhl_parm_set("qosInip", v4);
  if ( v1 || v2 )
  {
    if ( (*v1 & 0xDF) == 0 )
    {
      v1 = (char *)nvram_get("qosFip");
      if ( !v1 )
        v1 = "";
    }
    if ( (*v2 & 0xDF) == 0 )
    {
      v2 = (char *)nvram_get("qosDns");
      if ( !v2 )
        v2 = "";
    }
    if ( !v3 || (*v3 & 0xDF) == 0 )
    {
      v3 = (char *)nvram_get("qosProt");
      if ( !v3 )
        v3 = "";
    }
    if ( !v4 || (*v4 & 0xDF) == 0 )
    {
      v4 = (char *)nvram_get("qosInip");
      if ( !v4 )
        v4 = "";
    }
    v29 = (char *)v25;
    v25[0] = (int)"wys";
    v25[1] = (int)"qos";
    v25[2] = (int)"dns_ip";
    v25[3] = (int)v2;
    v25[4] = (int)v1;
    v25[5] = (int)v3;
    v25[6] = (int)v4;
    v25[7] = 0;
    eval(v25, 0, 0, 0);
  }
  else
  {
    v29 = (char *)v25;
  }
  if ( v26 )
  {
    v27 = cJSON_GetArraySize(v26);
    if ( v27 > 0 )
    {
      v28 = "a";
      v6 = 0;
      v30 = "a";
      do
      {
        v7 = cJSON_GetArrayItem(v26, v6);
        v8 = cJSON_GetObjectItem(v7, v28 + 13148);
        v9 = cJSON_GetIntvalue(v8);
        v10 = *(_DWORD **)(v7 + 8);
        v11 = v9;
        if ( v10 )
        {
          v12 = 0;
          v13 = 0;
          do
          {
            while ( 1 )
            {
              v14 = (const char *)v10[8];
              v15 = v10[4];
              v10 = (_DWORD *)*v10;
              v16 = strcmp(v14, "up");
              v5 = v14;
              if ( v16 )
                break;
              v12 = v15;
              if ( !v10 )
                goto LABEL_28;
            }
            if ( !strcmp(v14, "down") )
              v13 = v15;
          }
          while ( v10 );
LABEL_28:
          if ( v12 && v13 )
          {
            v17 = v29;
            snprintf(v29, 128, v30 + 22708, v12, v13);
            qos_parm_apply(v11, (int)v17, 1);
          }
        }
        ++v6;
      }
      while ( v27 != v6 );
    }
  }
  jhl_parm_commit(v5);
  v18 = v29;
  v19 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v20 = *(_DWORD *)v19;
    v21 = *((_DWORD *)v19 + 1);
    v22 = *((_DWORD *)v19 + 2);
    v23 = *((_DWORD *)v19 + 3);
    v19 += 16;
    *(_DWORD *)v18 = v20;
    *((_DWORD *)v18 + 1) = v21;
    *((_DWORD *)v18 + 2) = v22;
    *((_DWORD *)v18 + 3) = v23;
    v18 += 16;
  }
  while ( v19 != "}" );
  *(_WORD *)v18 = *(_WORD *)v19;
  return httpd_cgi_ret(a1, v29, 33, 4);
}
// 458960: variable 'v5' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

