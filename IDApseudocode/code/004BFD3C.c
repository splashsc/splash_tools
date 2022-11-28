int __fastcall mr_list_get(int a1, int a2, int a3)
{
  int v5; // $v0
  int v7; // $v1
  int v8; // $s0
  int v9; // $s3
  int v10; // $s4
  int v11; // $v0
  int v12; // $v0
  int v13; // $v0
  int v14; // $a1
  int (__fastcall *v15)(const char *, int); // $t9
  const char *v16; // $a0
  int v17; // $v0
  int v18; // $s2
  int v19; // $v0
  int v20; // $v0
  int v21; // $v0
  unsigned int v22; // $a0
  int v23; // $s2
  unsigned int v24; // $s2
  int v25; // $v0
  int v26; // $v0
  int v27; // $v0
  int v28; // $v0
  char v30[32]; // [sp+58h] [-60h] BYREF
  _DWORD v31[8]; // [sp+78h] [-40h] BYREF
  int v32; // [sp+98h] [-20h]
  char *v33; // [sp+9Ch] [-1Ch]
  char *v34; // [sp+A0h] [-18h]
  const char *v35; // [sp+A4h] [-14h]
  char *v36; // [sp+A8h] [-10h]
  const char *v37; // [sp+ACh] [-Ch]
  char *v38; // [sp+B0h] [-8h]
  char *format; // [sp+B4h] [-4h]

  v5 = nvram_match_def("ping_wan_gw", "1");
  v7 = *(_DWORD *)(a1 + 4);
  v32 = v5;
  if ( v7 <= 0 || (v8 = a1 + 8, a3 < 100) )
  {
    v28 = 0;
    v9 = 0;
    goto LABEL_22;
  }
  v34 = "1\"";
  v9 = 0;
  v33 = "1\"";
  v10 = 0;
  format = "%lu/200";
  v35 = "vpn_flow_all";
  v36 = "1\"";
  v38 = "a";
  v37 = "wan_flow_all";
  do
  {
    v31[0] = 0;
    v31[1] = 0;
    v31[2] = 0;
    v31[3] = 0;
    v31[4] = 0;
    v31[5] = 0;
    v31[6] = 0;
    v31[7] = 0;
    v22 = *(unsigned __int16 *)(v8 + 8);
    v23 = v22 - 1;
    if ( v32 && v22 < 0x65 )
    {
      v27 = ping_wan_gw_get_state(v22 - 1);
      sprintf((char *)v31, format, v27);
      v22 = *(unsigned __int16 *)(v8 + 8);
      v23 = v22 - 1;
    }
    if ( v23 < 101 )
    {
      v11 = jhl_nvget(v37, v23);
      v12 = nvram_get(v11);
      if ( !v12 )
        v12 = (int)(v38 + 14076);
      v13 = J_atoi(v12);
      v14 = v23;
      v15 = (int (__fastcall *)(const char *, int))&jhl_nvget;
      v16 = "wan_flow_use";
    }
    else
    {
      v24 = v22 - 102;
      v25 = jhl_vpnget(v35, v22 - 102);
      v26 = nvram_get(v25);
      if ( !v26 )
        v26 = (int)(v38 + 14076);
      v13 = J_atoi(v26);
      v14 = v24;
      v15 = (int (__fastcall *)(const char *, int))&jhl_vpnget;
      v16 = v36 - 292;
    }
    v18 = v13;
    v17 = v15(v16, v14);
    v19 = nvram_get(v17);
    if ( !v19 )
      v19 = (int)(v38 + 14076);
    v20 = J_atoi(v19);
    sprintf(v30, v34 - 276, v20, v18 << 10, *(unsigned __int8 *)(v8 + 10));
    v21 = snprintf(
            (char *)(a2 + v9),
            a3,
            v33 - 264,
            *(unsigned __int16 *)(v8 + 8),
            *(unsigned __int8 *)(v8 + 2),
            *(unsigned __int8 *)(v8 + 7),
            *(unsigned __int8 *)(v8 + 1),
            *(_DWORD *)(v8 + 20),
            *(unsigned __int8 *)(v8 + 132),
            *(_DWORD *)(v8 + 12),
            *(_DWORD *)(v8 + 16),
            *(_DWORD *)(v8 + 24),
            *(_DWORD *)(v8 + 28),
            *(_DWORD *)(v8 + 32),
            *(_DWORD *)(v8 + 36),
            *(_DWORD *)(v8 + 40),
            v31,
            *(_DWORD *)(v8 + 120),
            v30,
            101);
    if ( v21 >= a3 )
      v21 = a3 - 1;
    ++v10;
    v9 += v21;
    a3 -= v21;
    v8 += 352;
  }
  while ( v10 < *(_DWORD *)(a1 + 4) && a3 >= 100 );
  if ( v9 <= 0 )
    goto LABEL_24;
  v28 = v9;
  if ( *(_BYTE *)(a2 + v9 - 1) == 44 )
  {
    --v9;
LABEL_24:
    v28 = v9;
  }
LABEL_22:
  *(_BYTE *)(a2 + v28) = 0;
  return v9;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A88C0: using guessed type int __fastcall ping_wan_gw_get_state(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

