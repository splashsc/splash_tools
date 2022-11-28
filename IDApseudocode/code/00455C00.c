void __fastcall qos_parm_apply(int a1, int a2, int a3)
{
  _BOOL4 v3; // $s3
  int v7; // $v0
  const char *v8; // $v0
  int v9; // $v0
  int v10; // $v0
  int v11; // $s5
  int v12; // $s4
  char *v13; // $fp
  int v14; // $v0
  char *v15; // $s2
  int v16; // $v0
  int v17; // $v0
  int v18; // $s5
  int v19; // $s7
  int v20[128]; // [sp+38h] [-6F0h] BYREF
  char v21[512]; // [sp+238h] [-4F0h] BYREF
  char v22[512]; // [sp+438h] [-2F0h] BYREF
  int v23; // [sp+638h] [-F0h] BYREF
  int v24; // [sp+63Ch] [-ECh]
  char *v25; // [sp+640h] [-E8h]
  char *v26; // [sp+678h] [-B0h] BYREF
  const char *v27; // [sp+67Ch] [-ACh]
  char *v28; // [sp+680h] [-A8h]
  char *v29; // [sp+684h] [-A4h]
  const char *v30; // [sp+688h] [-A0h]
  const char *v31; // [sp+68Ch] [-9Ch]
  const char *v32; // [sp+690h] [-98h]
  const char *v33; // [sp+694h] [-94h]
  const char *v34; // [sp+698h] [-90h]
  char *v35; // [sp+69Ch] [-8Ch]
  char *v36; // [sp+6A0h] [-88h]
  const char *v37; // [sp+6A4h] [-84h]
  char *v38; // [sp+6A8h] [-80h]
  char *v39; // [sp+6ACh] [-7Ch]
  char v40[32]; // [sp+6B8h] [-70h] BYREF
  char v41[32]; // [sp+6D8h] [-50h] BYREF
  int v42; // [sp+6F8h] [-30h]

  if ( !a2 )
    return;
  v3 = a1 < 101;
  if ( a1 < 101 )
    v7 = jhl_nvget("qos_dk", a1);
  else
    v7 = jhl_vpnget("vpnqos_dk", a1 - 101);
  v8 = (const char *)nvram_get(v7);
  if ( v8 && *v8 )
  {
    v42 = 0;
  }
  else
  {
    v42 = 1;
    v8 = "on|hi|0|0|75|85|1000|2000|5|10|4|1500|8|16";
  }
  strlcpy(v22, v8, 512);
  v9 = split_string(v22, 124, &v26, 14);
  v26 = "on";
  if ( v9 < 14 )
  {
    v28 = "0";
    v29 = "0";
    v30 = "75";
    v27 = "hi";
    v31 = "85";
    v32 = "1000";
    v33 = "2000";
    v34 = (const char *)&unk_4D15F8;
    v35 = "10";
    v36 = "4";
    v37 = "1500";
    v38 = "8";
    v39 = "16";
  }
  strlcpy(v21, a2, 512);
  v10 = split_string(v21, 124, &v23, 14);
  if ( v10 == 2 )
  {
    v18 = J_atoi(v23);
    v19 = J_atoi(v24);
    sprintf(v41, "%u", v18);
    sprintf(v40, "%u", v19);
    if ( strcmp(v28, v41) || strcmp(v29, v40) )
    {
      v28 = v41;
      v29 = v40;
      goto LABEL_18;
    }
  }
  else
  {
    if ( v10 != 3 )
      return;
    v11 = J_atoi(v23);
    v12 = J_atoi(v24);
    sprintf(v41, "%u", v11);
    sprintf(v40, "%u", v12);
    v13 = v25;
    if ( strcmp(v25, "on") && strcmp(v13, (const char *)&off_63F984) )
    {
      v25 = "on";
      v13 = "on";
    }
    if ( strcmp(v28, v41) || strcmp(v29, v40) || strcmp(v26, v13) )
    {
      v28 = v41;
      v29 = v40;
      v26 = v13;
      goto LABEL_18;
    }
  }
  if ( !v42 )
    return;
LABEL_18:
  if ( !a3 )
    goto LABEL_22;
  if ( !v3 )
  {
    v17 = jhl_vpnget(&unk_645880, a1 - 101);
    v15 = (char *)nvram_get(v17);
    if ( !v15 )
      v15 = "";
    v14 = jhl_get_wan_proto(a1);
    if ( !*v15 )
      goto LABEL_22;
    goto LABEL_33;
  }
  v15 = (char *)jhl_get_wan_name(a1);
  v14 = jhl_get_wan_proto(a1);
  if ( v15 && *v15 )
  {
LABEL_33:
    if ( v14 )
    {
      v20[0] = (int)"wys";
      v20[1] = (int)"qos";
      v20[2] = (int)"set";
      v20[4] = (int)v26;
      v20[5] = (int)v27;
      v20[6] = (int)v28;
      v20[3] = (int)v15;
      v20[7] = (int)v29;
      v20[8] = (int)v30;
      v20[9] = (int)v31;
      v20[10] = (int)v32;
      v20[11] = (int)v33;
      v20[12] = (int)v34;
      v20[13] = (int)v35;
      v20[14] = (int)v36;
      v20[15] = (int)v37;
      v20[16] = (int)v38;
      v20[17] = (int)v39;
      v20[18] = 0;
      eval(v20, 0, 0, 0);
      mr_set(a1);
    }
  }
LABEL_22:
  sprintf(
    (char *)v20,
    "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39);
  if ( v3 )
    v16 = jhl_nvget("qos_dk", a1);
  else
    v16 = jhl_vpnget("vpnqos_dk", a1 - 101);
  nvram_set(v16, v20);
}
// 63F984: using guessed type void *off_63F984;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8688: using guessed type int __fastcall jhl_get_wan_name(_DWORD);
// 6A8708: using guessed type int __fastcall mr_set(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

