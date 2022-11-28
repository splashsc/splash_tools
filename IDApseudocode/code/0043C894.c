int __fastcall sub_43C894(int a1)
{
  char *v1; // $v0
  int v2; // $v0
  int v3; // $s2
  int v4; // $s6
  int v5; // $fp
  int v6; // $s7
  int v7; // $s0
  int v8; // $s4
  int v9; // $s3
  int v10; // $v0
  int v11; // $s5
  unsigned int v12; // $s0
  const char *v13; // $a2
  const char *v14; // $v0
  unsigned int v15; // $v0
  int v16; // $v0
  char *v17; // $s5
  int v18; // $s0
  char *v19; // $v0
  char *v20; // $s6
  int v21; // $v0
  char *v22; // $a0
  char *v23; // $v1
  const char *v24; // $v0
  int v25; // $t0
  int v26; // $a3
  int v27; // $a2
  int v28; // $a1
  int v29; // $a1
  int v30; // $a0
  char v31; // $v0
  int v32; // $s5
  int v33; // $v0
  const char *v34; // $v0
  char *v35; // $a3
  char *v36; // $a0
  const char *v37; // $v1
  int v38; // $a0
  char *v39; // $v1
  const char *v40; // $v0
  int v41; // $t0
  int v42; // $a3
  int v43; // $a2
  int v44; // $a1
  int v46; // $v0
  _DWORD *v47; // $v1
  const char *v48; // $v0
  int v49; // $t0
  int v50; // $a3
  int v51; // $a2
  int v52; // $a1
  int v53; // $a1
  int v54; // $a0
  char v55; // $v0
  char v56[512]; // [sp+28h] [-540h] BYREF
  char v57[512]; // [sp+228h] [-340h] BYREF
  char v58[256]; // [sp+428h] [-140h] BYREF
  char *nptr; // [sp+528h] [-40h] BYREF
  char *v60; // [sp+52Ch] [-3Ch]
  const char *v61; // [sp+530h] [-38h]
  const char *v62; // [sp+534h] [-34h]
  int v63; // [sp+538h] [-30h]
  int v64; // [sp+53Ch] [-2Ch]
  char *v65; // [sp+540h] [-28h]
  const char *v66; // [sp+544h] [-24h]
  const char *v67; // [sp+548h] [-20h]
  char *v68; // [sp+54Ch] [-1Ch]
  char *format; // [sp+550h] [-18h]
  void *s; // [sp+554h] [-14h]
  int v71; // [sp+558h] [-10h]
  const char *v72; // [sp+55Ch] [-Ch]
  char *v73; // [sp+560h] [-8h]

  memset(v57, 0, sizeof(v57));
  s = v56;
  memset(v56, 0, sizeof(v56));
  v73 = v58;
  nptr = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  memset(v58, 0, sizeof(v58));
  v1 = httpd_get_parm(a1, "mod_vid");
  if ( v1 )
    v71 = atoi(v1);
  else
    v71 = -1;
  memset(s, 0, 0x200u);
  v2 = httpd_get_json_parm(a1, (int)"all");
  v3 = v2;
  if ( v2 )
  {
    v4 = cJSON_GetArraySize(v2);
    if ( v4 <= 0 )
    {
LABEL_15:
      v16 = v57[0];
      v17 = v57;
      if ( v57[0] == 48 )
      {
        v18 = 0;
        goto LABEL_17;
      }
    }
    else
    {
      v65 = "1\"";
      v66 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
      v72 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
      v67 = "port";
      v68 = "m";
      v5 = 0;
      v6 = 0;
      format = "%s|%s|%s|%s>";
      while ( 1 )
      {
        v7 = cJSON_GetArrayItem(v3, v5);
        v8 = cJSON_GetObjectItem(v7, v67);
        v9 = cJSON_GetObjectItem(v7, v68);
        v11 = cJSON_GetObjectItem(v7, v65 - 31056);
        v10 = cJSON_GetObjectItem(v7, v66 + 6420);
        if ( !v8 || !v9 )
          break;
        v12 = 512 - v6;
        if ( v11 )
          v13 = *(const char **)(v11 + 16);
        else
          v13 = v72 - 1556;
        if ( v10 )
          v14 = *(const char **)(v10 + 16);
        else
          v14 = v72 - 1556;
        v15 = snprintf(&v57[v6], v12, format, *(_DWORD *)(v8 + 16), *(_DWORD *)(v9 + 16), v13, v14);
        if ( v15 >= v12 )
          v15 = 511 - v6;
        ++v5;
        v6 += v15;
        if ( v4 == v5 )
          goto LABEL_15;
      }
      v57[0] = 0;
    }
  }
  v23 = v73;
  v24 = "0|0>1|0>2|0>3|0>4|0>5|0>6|0>7|0>8|0>9|0>";
  do
  {
    v25 = *(_DWORD *)v24;
    v26 = *((_DWORD *)v24 + 1);
    v27 = *((_DWORD *)v24 + 2);
    v28 = *((_DWORD *)v24 + 3);
    v24 += 16;
    *(_DWORD *)v23 = v25;
    *((_DWORD *)v23 + 1) = v26;
    *((_DWORD *)v23 + 2) = v27;
    *((_DWORD *)v23 + 3) = v28;
    v23 += 16;
  }
  while ( v24 != "8|0>9|0>" );
  v29 = *(_DWORD *)v24;
  v30 = *((_DWORD *)v24 + 1);
  v31 = v24[8];
  *(_DWORD *)v23 = v29;
  *((_DWORD *)v23 + 1) = v30;
  v23[8] = v31;
  v16 = v58[0];
  v17 = v73;
  v18 = 0;
LABEL_17:
  while ( v16 )
  {
    v19 = strchr(v17, 62);
    v20 = v19;
    if ( v19 )
    {
      *v19 = 0;
      v21 = split_string(v17, 124, &nptr, 4);
      v22 = v20 + 1;
      if ( v21 != 4 )
        goto LABEL_20;
      ++v20;
    }
    else if ( split_string(v17, 124, &nptr, 4) != 4 )
    {
      break;
    }
    v32 = atoi(nptr);
    if ( v71 == -1 || (v33 = atoi(nptr), v71 == v33) )
    {
      v46 = atoi(v60);
      set_link_status_by_id(v32, v46);
      v34 = v61;
      v35 = v60;
      v36 = (char *)s + v18;
      if ( v61 )
      {
LABEL_32:
        v37 = v62;
        if ( !v62 )
          goto LABEL_41;
        goto LABEL_33;
      }
    }
    else
    {
      v34 = v61;
      v35 = v60;
      v36 = (char *)s + v18;
      if ( v61 )
        goto LABEL_32;
    }
    v37 = v62;
    v34 = "";
    if ( !v62 )
LABEL_41:
      v37 = "";
LABEL_33:
    v18 += sprintf(v36, "%d|%s|%s|%s>", v32, v35, v34, v37);
    v22 = v20;
LABEL_20:
    if ( !v22 )
      break;
    v16 = *v22;
    v17 = v22;
  }
  if ( !v56[0] )
  {
    v47 = s;
    v48 = "0|0>1|0>2|0>3|0>4|0>5|0>6|0>7|0>8|0>9|0>";
    do
    {
      v49 = *(_DWORD *)v48;
      v50 = *((_DWORD *)v48 + 1);
      v51 = *((_DWORD *)v48 + 2);
      v52 = *((_DWORD *)v48 + 3);
      v48 += 16;
      *v47 = v49;
      v47[1] = v50;
      v47[2] = v51;
      v47[3] = v52;
      v47 += 4;
    }
    while ( v48 != "8|0>9|0>" );
    v53 = *(_DWORD *)v48;
    v54 = *((_DWORD *)v48 + 1);
    v55 = v48[8];
    *v47 = v53;
    v47[1] = v54;
    *((_BYTE *)v47 + 8) = v55;
  }
  nvram_set("port_mode", s);
  jhl_parm_commit(v38);
  v39 = v57;
  v40 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v41 = *(_DWORD *)v40;
    v42 = *((_DWORD *)v40 + 1);
    v43 = *((_DWORD *)v40 + 2);
    v44 = *((_DWORD *)v40 + 3);
    v40 += 16;
    *(_DWORD *)v39 = v41;
    *((_DWORD *)v39 + 1) = v42;
    *((_DWORD *)v39 + 2) = v43;
    *((_DWORD *)v39 + 3) = v44;
    v39 += 16;
  }
  while ( v40 != "}" );
  *(_WORD *)v39 = *(_WORD *)v40;
  return httpd_cgi_ret(a1, v57, 33, 4);
}
// 43CD20: variable 'v38' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8228: using guessed type int __fastcall set_link_status_by_id(_DWORD, _DWORD);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

