int __fastcall get_wan_nvarms(const char **a1, char *a2, int a3)
{
  int v5; // $s5
  int v6; // $s3
  int v7; // $s0
  int v8; // $s7
  int v9; // $v0
  const char *v10; // $s1
  int v11; // $s2
  int v12; // $v0
  const char *v13; // $v0
  int v14; // $v0
  const char *v15; // $v0
  int v16; // $v0
  const char *v17; // $v1
  int v18; // $s3
  const char **v19; // $s1
  int v20; // $v0
  int v21; // $v0
  int v22; // $v0
  int v23; // $a3
  int v24; // $v0
  int v25; // $v1
  int v26; // $v0
  char *v27; // $v0
  int v28; // $v0
  int v29; // $v0
  int v30; // $s3
  int v31; // $v0
  int v32; // $s1
  int v33; // $s3
  int v34; // $v0
  const char *v35; // $v0
  int v36; // $s3
  int v37; // $v0
  int v38; // $s3
  int v39; // $v0
  int v40; // $v0
  int v41; // $s3
  int v42; // $v0
  int v43; // $s3
  int v44; // $s1
  int v45; // $v0
  char *v46; // $a0
  int v47; // $s4
  int v48; // $v0
  char *v50; // $a0
  int v51; // $v0
  int v52; // $a3
  int v53; // $v0
  const char *v54; // $s2
  int v55; // $v0
  const char *v56; // $v0
  int v57; // $v0
  char v58[512]; // [sp+20h] [-2E0h] BYREF
  char v59[128]; // [sp+220h] [-E0h] BYREF
  const char *v60[16]; // [sp+2A0h] [-60h] BYREF
  char *v61; // [sp+2E0h] [-20h]
  char *v62; // [sp+2E4h] [-1Ch]
  char *v63; // [sp+2E8h] [-18h]
  char *format; // [sp+2ECh] [-14h]
  const char *v65; // [sp+2F0h] [-10h]
  const char *v66; // [sp+2F4h] [-Ch]
  const char *v67; // [sp+2F8h] [-8h]
  char *v68; // [sp+2FCh] [-4h]

  v5 = sq_file_get_max_wan();
  v6 = snprintf(a2, a3, "\"wans\":[");
  if ( v6 >= a3 )
    v6 = a3 - 1;
  if ( v5 > 0 )
  {
    v65 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    v7 = 0;
    v62 = "a";
    v67 = "255.255.255.255";
    v63 = "wan_proto";
    format = ",\"%s\":\"%s\"";
    while ( 1 )
    {
      v9 = jhl_nvget("wan_ifname", v7);
      v10 = (const char *)nvram_get(v9);
      if ( !v10 )
        v10 = v65 - 1556;
      v11 = jhl_get_wan_proto(v7);
      if ( v11 == 4 )
      {
        v12 = jhl_nvget("ppp_demand_run", v7);
        v13 = (const char *)nvram_get(v12);
        if ( v13 && !strcmp(v13, "1") )
        {
          if ( !*v10 )
            break;
          v8 = 0;
        }
        else
        {
          v8 = jhl_check_wanup(v7);
          if ( !*v10 )
            break;
        }
      }
      else
      {
        v8 = jhl_check_wanup(v7);
        if ( !*v10 )
          break;
        if ( (unsigned int)(v11 - 10) < 3 )
          goto LABEL_7;
      }
      v14 = jhl_nvget(v62 + 12496, v7);
      v15 = (const char *)nvram_get(v14);
      if ( v15 && !strcmp(v15, "1") || jhl_iface_link_up_check(v10, v7) )
      {
LABEL_7:
        if ( v5 == ++v7 )
          break;
      }
      else
      {
        v61 = (char *)(a3 - v6);
        v16 = snprintf(&a2[v6], a3 - v6, "{\"iface\":%d,\"wan_ifname\":\"%s\"", v7, v10);
        if ( v16 >= (int)v61 )
          v16 = (int)(v61 - 1);
        v17 = *a1;
        v18 = v16 + v6;
        if ( *a1 && *v17 )
        {
          v19 = a1;
          v68 = ",\"%s\":\"\"";
          v66 = "wan_new_proto";
          do
          {
            v61 = (char *)v17;
            if ( !strcmp(v17, v63) )
            {
              v20 = jhl_nvget(v66, v7);
              v21 = nvram_get(v20);
              if ( v21 )
                goto LABEL_24;
              v50 = v63;
            }
            else
            {
              v50 = v61;
            }
            v51 = jhl_nvget(v50, v7);
            v21 = nvram_get(v51);
            if ( !v21 )
            {
              v52 = (int)*v19;
              v61 = (char *)(a3 - v18);
              v24 = snprintf(&a2[v18], a3 - v18, v68, v52);
              v25 = (int)v61;
              if ( v24 < (int)v61 )
                goto LABEL_25;
              goto LABEL_57;
            }
LABEL_24:
            v61 = (char *)*v19;
            v22 = get_json_data(v21);
            v23 = (int)v61;
            v61 = (char *)(a3 - v18);
            v24 = snprintf(&a2[v18], a3 - v18, format, v23, v22);
            v25 = (int)v61;
            if ( v24 < (int)v61 )
              goto LABEL_25;
LABEL_57:
            v24 = v25 - 1;
LABEL_25:
            v17 = *++v19;
            v18 += v24;
          }
          while ( *v19 && *v17 );
        }
        v26 = jhl_nvget("mr_parm", v7);
        v27 = (char *)nvram_get(v26);
        if ( !v27 || !*v27 )
          v27 = " ";
        v61 = v58;
        strlcpy(v58, v27, 512);
        v28 = split_string(v61, 60, v60, 14);
        mr_parm_default(v28, v60, v7);
        v29 = snprintf(&a2[v18], a3 - v18, ",\"mr_zc_en\":\"%s\"", v60[2]);
        if ( v29 >= a3 - v18 )
          v29 = a3 - v18 - 1;
        v30 = v29 + v18;
        v31 = snprintf(&a2[v30], a3 - v30, ",\"mr_jh_en\":\"%s\"", v60[0]);
        if ( v31 >= a3 - v30 )
          v31 = a3 - v30 - 1;
        v32 = v31 + v30;
        v33 = a3 - (v31 + v30);
        v34 = snprintf(&a2[v32], v33, ",\"host\":\"%s\"", v60[12]);
        if ( v34 >= v33 )
          v34 = v33 - 1;
        v36 = v34 + v32;
        v35 = (const char *)jhl_get_wanstatus(v7);
        v37 = snprintf(&a2[v36], a3 - v36, ",\"wan_state\":\"%s\"", v35);
        if ( v37 >= a3 - v36 )
          v37 = a3 - v36 - 1;
        v38 = v37 + v36;
        jhl_link_uptime(v59, v7, v8);
        v61 = (char *)(a3 - v38);
        v39 = snprintf(&a2[v38], a3 - v38, ",\"wan_uptime\":\"%s\"", v59);
        if ( v39 >= (int)v61 )
          v39 = (int)(v61 - 1);
        v41 = v39 + v38;
        v40 = jhl_link_uptime_s(v7, v8);
        v42 = snprintf(&a2[v41], a3 - v41, ",\"connect_time\":%ld", v40);
        if ( v42 >= a3 - v41 )
          v42 = a3 - v41 - 1;
        v43 = v42 + v41 + get_iface_increase_data(v7, &a2[v42 + v41], a3 - (v42 + v41));
        v44 = v43 + get_iface_pppoe_br_data(v7, &a2[v43], a3 - v43);
        if ( v11 == 4 )
        {
          v53 = jhl_nvget("ppp_get_ip", v7);
          v54 = (const char *)nvram_get(v53);
          if ( !v54 )
            v54 = "0.0.0.0";
          v55 = jhl_nvget("ppp_gw", v7);
          v56 = (const char *)nvram_get(v55);
          if ( !v56 )
            v56 = v54;
          v57 = snprintf(
                  &a2[v44],
                  a3 - v44,
                  ",\"ppp_wan_ip\":\"%s\",\"ppp_wan_mask\":\"%s\",\"ppp_wan_gw\":\"%s\"",
                  v54,
                  v67,
                  v56);
          if ( v57 >= a3 - v44 )
            v57 = a3 - v44 - 1;
          v44 += v57;
        }
        v45 = snprintf(&a2[v44], a3 - v44, &byte_65078C);
        if ( v45 >= a3 - v44 )
          v45 = a3 - v44 - 1;
        ++v7;
        v6 = v44 + v45;
        if ( v5 == v7 )
          break;
      }
    }
  }
  v46 = &a2[v6];
  if ( v6 > 0 && *(v46 - 1) == 44 )
    v46 = &a2[--v6];
  v47 = a3 - v6;
  *v46 = 0;
  v48 = snprintf(v46, v47, "],");
  if ( v48 >= v47 )
    v48 = v47 - 1;
  return v6 + v48;
}
// 65078C: using guessed type char byte_65078C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8270: using guessed type int __fastcall mr_parm_default(_DWORD, _DWORD, _DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84E0: using guessed type int __fastcall jhl_get_wanstatus(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);

