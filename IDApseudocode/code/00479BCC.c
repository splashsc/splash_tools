int __fastcall user_get_state(int a1, char *a2, int a3)
{
  char *v3; // $s3
  char *v4; // $s1
  int v5; // $fp
  _DWORD *v6; // $v0
  int v7; // $a2
  _DWORD *v8; // $s4
  char *v9; // $a0
  int v10; // $v0
  int v11; // $s0
  _DWORD *v13; // $s0
  int v14; // $s3
  int v15; // $lo
  int v16; // $v0
  int v17; // $v1
  int v18; // $s4
  int v19; // $s1
  int v20; // $v0
  int v21; // $v0
  int v22; // $a1
  int v23; // $a1
  size_t v24; // $v0
  size_t v25; // $v0
  size_t v26; // $v0
  size_t v27; // $v0
  size_t v28; // $v0
  size_t v29; // $v0
  __int16 v30; // $a3
  int v31; // $v0
  int v32; // $v0
  int v33; // $v0
  char v34[1024]; // [sp+80h] [-10F0h] BYREF
  char v35[1024]; // [sp+480h] [-CF0h] BYREF
  char v36[1024]; // [sp+880h] [-8F0h] BYREF
  char v37[1024]; // [sp+C80h] [-4F0h] BYREF
  int v38; // [sp+1080h] [-F0h] BYREF
  int v39; // [sp+1084h] [-ECh]
  int v40; // [sp+1088h] [-E8h]
  int v41; // [sp+108Ch] [-E4h]
  int v42; // [sp+1090h] [-E0h]
  int v43; // [sp+1094h] [-DCh]
  int v44; // [sp+1098h] [-D8h]
  int v45; // [sp+109Ch] [-D4h]
  int v46; // [sp+10A0h] [-D0h]
  int v47; // [sp+10A4h] [-CCh]
  int v48; // [sp+10A8h] [-C8h]
  int v49; // [sp+10ACh] [-C4h]
  int v50; // [sp+10B0h] [-C0h] BYREF
  int v51; // [sp+10B4h] [-BCh]
  int v52; // [sp+10B8h] [-B8h]
  int v53; // [sp+10BCh] [-B4h]
  int v54; // [sp+10C0h] [-B0h]
  int v55; // [sp+10C4h] [-ACh]
  int v56; // [sp+10C8h] [-A8h]
  int v57; // [sp+10CCh] [-A4h]
  int v58[8]; // [sp+10D0h] [-A0h] BYREF
  int v59; // [sp+10F0h] [-80h] BYREF
  int v60; // [sp+10F4h] [-7Ch]
  int v61; // [sp+10F8h] [-78h]
  int v62; // [sp+10FCh] [-74h]
  int v63; // [sp+1100h] [-70h]
  int v64; // [sp+1104h] [-6Ch]
  int v65; // [sp+1108h] [-68h]
  int v66; // [sp+110Ch] [-64h]
  int v67; // [sp+1110h] [-60h] BYREF
  int v68; // [sp+1114h] [-5Ch]
  int v69; // [sp+1118h] [-58h]
  int v70; // [sp+111Ch] [-54h]
  int v71; // [sp+1120h] [-50h]
  int v72; // [sp+1124h] [-4Ch]
  int v73; // [sp+1128h] [-48h]
  int v74; // [sp+112Ch] [-44h]
  int v75; // [sp+1130h] [-40h] BYREF
  __int16 v76; // [sp+1134h] [-3Ch]
  char *v77; // [sp+1138h] [-38h]
  char *v78; // [sp+113Ch] [-34h]
  int v79; // [sp+1140h] [-30h]
  char *str; // [sp+1144h] [-2Ch]
  int v81; // [sp+1148h] [-28h]
  _DWORD *v82; // [sp+114Ch] [-24h]
  char *format; // [sp+1150h] [-20h]
  int v84; // [sp+1154h] [-1Ch]
  char *v85; // [sp+1158h] [-18h]
  char *v86; // [sp+115Ch] [-14h]
  char *v87; // [sp+1160h] [-10h]
  char *v88; // [sp+1164h] [-Ch]
  char *v89; // [sp+1168h] [-8h]

  v67 = 0;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  v65 = 0;
  v66 = 0;
  v58[0] = 0;
  v58[1] = 0;
  v58[2] = 0;
  v58[3] = 0;
  v58[4] = 0;
  v58[5] = 0;
  v58[6] = 0;
  v58[7] = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v77 = v36;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  memset(v37, 0, sizeof(v37));
  memset(v36, 0, sizeof(v36));
  v78 = v35;
  memset(v35, 0, sizeof(v35));
  memset(v34, 0, sizeof(v34));
  v75 = 0;
  v76 = 0;
  v3 = httpd_get_parm(a1, "page");
  v4 = httpd_get_parm(a1, "limit");
  if ( *(_BYTE *)(a1 + 210100) == 2 )
    format = "%u|%s|%s|%s-%s|%s|%u|%u|%s|%u|%u|%u|%d|%d|%d|%d|%s|%d|%d|%s|%d|%s|%s|%d|%d|%d<";
  else
    format = "{\"cstate\":%u,\"user\":\"%s\",\"pwd\":\"%s\",\"ips\":\"%s-%s\",\"mac\":\"%s\",\"gid\":%u,\"ddate\":%u,\"me"
             "m\":\"%s\",\"zup\":%u,\"zdown\":%u,\"tm\":%u,\"state\":%d,\"num\":%d,\"speed_up\":%d,\"speed_down\":%d,\"sp"
             "eed_mode\":\"%s\",\"mod_pwd\":\"%d\",\"vlan\":%d,\"group\":\"%s\",\"vlan2\":%d,\"ip_login\":\"%s\",\"mac_lo"
             "gin\":\"%s\",\"bs_repeat_en\":%d,\"bs_interval\":%d,\"bs_count\":%d},";
  v5 = snprintf(a2, a3, (char *)&word_642A04);
  if ( v5 >= a3 )
    v5 = a3 - 1;
  v88 = "1\"";
  _mem_malloc(0x200000, "user_get_state", 1022);
  v82 = v6;
  if ( v6 )
  {
    *v6 = 16;
    v6[3] = 10;
    v6[1] = 0x200000;
    v8 = v6;
    if ( !jianhl_order_opt_fun(v6, 0x200000, v7) )
    {
      v13 = v8 + 6;
      if ( v3 && v4 )
      {
        v14 = J_atoi(v3);
        v15 = (v14 - 1) * J_atoi(v4);
        v79 = v15;
        v16 = J_atoi(v4);
        v17 = v8[5];
        v84 = v16 - 1 + v15;
      }
      else
      {
        v79 = 0;
        v17 = v82[5];
        v84 = v17;
      }
      if ( v17 > 0 )
      {
        v18 = 0;
        v86 = "1\"";
        v89 = "1\"";
        v87 = "1\"";
        v85 = "%s";
        do
        {
          if ( v18 >= v79 )
          {
            if ( v84 < v18 )
              break;
            v67 = 0;
            v59 = 0;
            v68 = 0;
            v69 = 0;
            v70 = 0;
            v71 = 0;
            v72 = 0;
            v73 = 0;
            v74 = 0;
            v60 = 0;
            v61 = 0;
            v62 = 0;
            v63 = 0;
            v64 = 0;
            v65 = 0;
            v66 = 0;
            memset(v37, 0, sizeof(v37));
            memset(v77, 0, 0x400u);
            memset(v78, 0, 0x400u);
            v21 = v13[77] & 0x21;
            v38 = 0;
            v50 = 0;
            v39 = 0;
            v40 = 0;
            v41 = 0;
            v42 = 0;
            v43 = 0;
            v44 = 0;
            v45 = 0;
            v46 = 0;
            v47 = 0;
            v48 = 0;
            v49 = 0;
            v51 = 0;
            v52 = 0;
            v53 = 0;
            v54 = 0;
            v55 = 0;
            v56 = 0;
            v57 = 0;
            if ( v21 )
            {
              v22 = v13[65];
              if ( v22 )
                IpToStr(&v67, v22);
              v23 = v13[66];
              if ( v23 )
                IpToStr(&v59, v23);
            }
            if ( *(_BYTE *)(a1 + 210100) == 2 )
            {
              v31 = get_json_data(v13);
              snprintf(v37, 1024, v85, v31);
              v32 = get_json_data(v13 + 16);
              snprintf(v77, 1024, v85, v32);
              v33 = get_json_data(v13 + 32);
              snprintf(v78, 1024, v85, v33);
            }
            else
            {
              memset(v34, 0, sizeof(v34));
              v24 = strlen((const char *)v13);
              str_to_utf8(v13, v24, v34, 1024);
              v25 = strlen(v34);
              base64_encode(v34, v37, v25);
              memset(v34, 0, sizeof(v34));
              str = (char *)(v13 + 16);
              v26 = strlen((const char *)v13 + 64);
              str_to_utf8(str, v26, v34, 1024);
              v27 = strlen(v34);
              base64_encode(v34, v77, v27);
              memset(v34, 0, sizeof(v34));
              str = (char *)(v13 + 32);
              v28 = strlen((const char *)v13 + 128);
              str_to_utf8(str, v28, v34, 1024);
              v29 = strlen(v34);
              base64_encode(v34, v78, v29);
            }
            IpaddrToStr2(&v38, v13 + 113);
            str = (char *)(v13 + 118);
            if ( memcmp(v13 + 118, &v75, 6u) )
              MacToStr(&v50, str);
            v30 = *((_WORD *)v13 + 154);
            str = &a2[v5];
            v81 = a3 - v5;
            if ( (v30 & 2) != 0 )
              MacToStr(v58, v13 + 71);
            v19 = v81;
            v20 = snprintf(str, v81, format);
            if ( v20 >= v19 )
              v20 = v19 - 1;
            v5 += v20;
            v13 += 122;
            if ( v5 >= a3 - 49 )
              break;
            v17 = v82[5];
          }
          ++v18;
        }
        while ( v18 < v17 );
      }
    }
  }
  v9 = &a2[v5];
  if ( v5 > 0 && *(v9 - 1) == 44 )
    v9 = &a2[--v5];
  *v9 = 0;
  v10 = snprintf(v9, a3 - v5, &byte_6445A0);
  v11 = v5 + v10;
  if ( v10 >= a3 - v5 )
    v11 = a3 - 1;
  _mem_free(v82);
  return v11;
}
// 479E10: variable 'v6' is possibly undefined
// 479E38: variable 'v7' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A8474: using guessed type int __fastcall base64_encode(_DWORD, _DWORD, _DWORD);
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A87E0: using guessed type int __fastcall IpaddrToStr2(_DWORD, _DWORD);
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A8904: using guessed type int __fastcall str_to_utf8(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

