int __fastcall get_vpn_state(char *a1, int a2)
{
  int v4; // $s4
  int v5; // $s0
  int v6; // $s1
  int v7; // $v0
  int v8; // $fp
  const char *v9; // $s5
  int v10; // $v0
  int v11; // $s0
  char *v12; // $a0
  char *v13; // $v0
  int v14; // $v0
  char *v15; // $a0
  int v16; // $s2
  int v17; // $v0
  int v19; // $v0
  int v20; // $v1
  int v21; // $v0
  int v22; // $fp
  int v23; // $v0
  int v24; // $v0
  int v25; // $v0
  int v26; // $v0
  int v27; // $fp
  int v28; // $v0
  int v29; // $v0
  int v30; // $v0
  int v31; // $v0
  int v32; // $fp
  int v33; // $v0
  int v34; // $s0
  int v35; // $v0
  int v36; // $v0
  int v37; // $v0
  int v38; // $s0
  const char *v39; // $v0
  int v40; // $fp
  int v41; // $v0
  int v42; // $v0
  int v43; // $s0
  const char *v44; // $v0
  int v45; // $fp
  int v46; // $v0
  int v47; // $v0
  int v48; // $s0
  const char *v49; // $v0
  int v50; // $fp
  int v51; // $v0
  int v52; // $v0
  int v53; // $s0
  const char *v54; // $v0
  int v55; // $fp
  int v56; // $v0
  int v57; // $v0
  const char *v58; // $v0
  int v59; // $fp
  int v60; // $v0
  int v61; // $v1
  char v62[128]; // [sp+20h] [-A0h] BYREF
  char *v63; // [sp+A0h] [-20h]
  char *v64; // [sp+A4h] [-1Ch]
  char *v65; // [sp+A8h] [-18h]
  const char *v66; // [sp+ACh] [-14h]
  char *format; // [sp+B0h] [-10h]
  char *v68; // [sp+B4h] [-Ch]
  char *v69; // [sp+B8h] [-8h]
  char *v70; // [sp+BCh] [-4h]

  v4 = sq_file_get_max_wan();
  v5 = snprintf(a1, a2, "\"state\":[ ");
  if ( v5 >= a2 )
    v5 = a2 - 1;
  if ( v4 > 0 )
  {
    v65 = "a";
    v64 = "1\"";
    v6 = 0;
    v68 = "1\"";
    v70 = "a";
    v66 = "vpn_run";
    format = "\"vpn_run\":\"%s\",";
    v69 = "\"vpn_run_wan\":\"WAN%lu\",";
    while ( 1 )
    {
      v7 = jhl_vpnget("vpn_new_proto", v6);
      v8 = a2 - v5;
      v9 = (const char *)nvram_get(v7);
      if ( v9 )
        break;
      v60 = jhl_vpnget("vpn_proto", v6);
      v9 = (const char *)nvram_get(v60);
      if ( v9 )
        break;
      v61 = snprintf(&a1[v5], a2 - v5, "{\"iface\":%d,\"vpn_proto\":\"%s\",", v6, v65 - 1660);
      v19 = 0;
      if ( v61 >= v8 )
      {
        v20 = v8 - 1;
        goto LABEL_22;
      }
      v11 = v61 + v5;
LABEL_8:
      v12 = &a1[v11];
      if ( v11 > 0 && *(v12 - 1) == 44 )
        v12 = &a1[--v11];
      v13 = v64;
      *v12 = 0;
      v14 = snprintf(v12, a2 - v11, v13 + 1932);
      if ( v14 >= a2 - v11 )
        v14 = a2 - v11 - 1;
      ++v6;
      v5 = v11 + v14;
      if ( v6 == 5 || v4 == v6 )
        goto LABEL_15;
    }
    v63 = (char *)snprintf(&a1[v5], a2 - v5, "{\"iface\":%d,\"vpn_proto\":\"%s\",", v6, v9);
    if ( (int)v63 >= v8 )
    {
      v19 = strcmp(v9, v65 - 1660);
      v20 = v8 - 1;
LABEL_22:
      v11 = v20 + v5;
      if ( !v19 )
        goto LABEL_8;
    }
    else
    {
      v10 = strcmp(v9, v65 - 1660);
      v11 = (int)&v63[v5];
      if ( !v10 )
        goto LABEL_8;
    }
    v21 = jhl_vpnget(v66, v6);
    v22 = nvram_get(v21);
    if ( !v22 )
      v22 = (int)(v70 + 14076);
    v63 = (char *)(a2 - v11);
    v23 = snprintf(&a1[v11], a2 - v11, format, v22);
    if ( v23 >= (int)v63 )
    {
      v11 += (int)(v63 - 1);
      v24 = J_atoi(v22);
      if ( v24 != 2 )
        goto LABEL_27;
    }
    else
    {
      v11 += v23;
      v24 = J_atoi(v22);
      if ( v24 != 2 )
      {
LABEL_27:
        if ( v24 != 1 )
          goto LABEL_8;
        v25 = jhl_vpnget(v68 - 19164, v6);
        v27 = a2 - v11;
        v26 = nvram_get(v25);
        if ( !v26 )
          v26 = (int)(v70 + 14076);
        v63 = &a1[v11];
        v28 = J_atoi(v26);
        v29 = snprintf(v63, a2 - v11, v69, v28 + 1);
        if ( v29 >= v27 )
          v29 = v27 - 1;
        goto LABEL_32;
      }
    }
    v63 = v62;
    jhl_vpn_link_uptime(v62, v6);
    v30 = snprintf(&a1[v11], a2 - v11, "\"vpn_time\":\"%s\",", v63);
    if ( v30 >= a2 - v11 )
      v30 = a2 - v11 - 1;
    v32 = v30 + v11;
    v31 = jhl_vpnget(v68 - 19164, v6);
    v34 = a2 - v32;
    v33 = nvram_get(v31);
    if ( !v33 )
      v33 = (int)(v70 + 14076);
    v63 = &a1[v32];
    v35 = J_atoi(v33);
    v36 = snprintf(v63, a2 - v32, v69, v35 + 1);
    if ( v36 >= v34 )
      v36 = v34 - 1;
    v38 = v36 + v32;
    v37 = jhl_vpnget("vpn_localip", v6);
    v40 = a2 - v38;
    v39 = (const char *)nvram_get(v37);
    if ( !v39 )
      v39 = " ";
    v41 = snprintf(&a1[v38], a2 - v38, "\"vpn_localip\":\"%s\",", v39);
    if ( v41 >= v40 )
      v41 = v40 - 1;
    v43 = v41 + v38;
    v42 = jhl_vpnget("vpn_peerip", v6);
    v45 = a2 - v43;
    v44 = (const char *)nvram_get(v42);
    if ( !v44 )
      v44 = " ";
    v46 = snprintf(&a1[v43], a2 - v43, "\"vpn_peerip\":\"%s\",", v44);
    if ( v46 >= v45 )
      v46 = v45 - 1;
    v48 = v46 + v43;
    v47 = jhl_vpnget(&unk_645880, v6);
    v50 = a2 - v48;
    v49 = (const char *)nvram_get(v47);
    if ( !v49 )
      v49 = " ";
    v51 = snprintf(&a1[v48], a2 - v48, "\"vpn_link\":\"%s\",", v49);
    if ( v51 >= v50 )
      v51 = v50 - 1;
    v53 = v51 + v48;
    v52 = jhl_vpnget("vpn_run_mtu", v6);
    v55 = a2 - v53;
    v54 = (const char *)nvram_get(v52);
    if ( !v54 )
      v54 = " ";
    v56 = snprintf(&a1[v53], a2 - v53, "\"vpn_run_mtu\":\"%s\",", v54);
    if ( v56 >= v55 )
      v56 = v55 - 1;
    v11 = v56 + v53;
    v57 = jhl_vpnget("vpn_get_dns", v6);
    v59 = a2 - v11;
    v58 = (const char *)nvram_get(v57);
    if ( !v58 )
      v58 = " ";
    v29 = snprintf(&a1[v11], a2 - v11, "\"vpn_get_dns\":\"%s\",", v58);
    if ( v29 >= v59 )
      v29 = v59 - 1;
LABEL_32:
    v11 += v29;
    goto LABEL_8;
  }
LABEL_15:
  v15 = &a1[v5];
  if ( v5 > 0 && *(v15 - 1) == 44 )
    v15 = &a1[--v5];
  v16 = a2 - v5;
  *v15 = 0;
  v17 = snprintf(v15, v16, "],");
  if ( v17 >= v16 )
    v17 = v16 - 1;
  return v5 + v17;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

