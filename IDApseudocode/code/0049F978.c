int __fastcall pppoe_bridge_session_get_state(int a1, int a2, int a3)
{
  _DWORD *v6; // $v0
  int v7; // $a2
  _DWORD *v8; // $s4
  int v9; // $v0
  int v10; // $fp
  int v12; // $v0
  char *v13; // $s6
  int v14; // $s2
  int v15; // $v0
  int v16; // $v0
  int v17; // $a3
  int v18; // $a2
  const char *v19; // $s5
  int v20; // $s7
  int v21; // $v0
  char v22[32]; // [sp+48h] [-58h] BYREF
  char v23[32]; // [sp+68h] [-38h] BYREF
  int v24; // [sp+88h] [-18h]
  int v25; // [sp+8Ch] [-14h]
  char *format; // [sp+90h] [-10h]
  char *v27; // [sp+94h] [-Ch]
  char *v28; // [sp+98h] [-8h]
  char *v29; // [sp+9Ch] [-4h]

  v28 = "1\"";
  _mem_malloc(0x200000, "pppoe_bridge_session_get_state", 2425);
  v8 = v6;
  if ( !v6 )
    goto LABEL_3;
  *v6 = 41;
  v6[3] = 12;
  v6[1] = 0x200000;
  if ( jianhl_order_opt_fun(v6, 0x200000, v7) )
    goto LABEL_3;
  v12 = v8[5];
  if ( a3 )
  {
    if ( v12 > 0 )
    {
      v25 = a2 - 49;
      v13 = (char *)v8 + 26;
      v29 = "%u";
      v10 = 0;
      format = "%u.%u";
      v14 = 0;
      v27 = "{\"session\":%u,\"mac\":\"%s\",\"user\":\"%s\",\"in_dev\":\"%s\",\"out_dev\":\"%s\",\"online_time\":%lu,\"qu"
            "p\":%u,\"qdw\":%u,\"zup\":%u,\"zdw\":%u,\"mem\":\"%s\",\"vlan\":\"%s\",\"vlan\":\"%s\"},";
      do
      {
        v17 = *((unsigned __int16 *)v13 + 142);
        v18 = *((unsigned __int16 *)v13 + 141);
        if ( *((_WORD *)v13 + 142) )
          sprintf(v22, format, v18, v17);
        else
          sprintf(v22, v29, v18, v17);
        v24 = ntohs(*((_WORD *)v13 - 1));
        v15 = MacToStr(v23, v13);
        v16 = snprintf(
                (char *)(a1 + v10),
                a2 - v10,
                v27,
                v24,
                v15,
                v13 + 58,
                v13 + 6,
                v13 + 22,
                *(_DWORD *)(v13 + 286),
                *(_DWORD *)(v13 + 42),
                *(_DWORD *)(v13 + 46),
                *(_DWORD *)(v13 + 50),
                *(_DWORD *)(v13 + 54),
                v13 + 122,
                v22,
                v13 + 250);
        if ( v16 >= a2 - v10 )
          v16 = a2 - v10 - 1;
        v10 += v16;
        ++v14;
        if ( v10 >= v25 )
          break;
        v13 += 292;
      }
      while ( v14 < v8[5] );
      goto LABEL_21;
    }
  }
  else if ( v12 > 0 )
  {
    v19 = (const char *)(v8 + 21);
    v10 = 0;
    v20 = 0;
    do
    {
      v21 = snprintf((char *)(a1 + v10), a2 - v10, "{\"user\":\"%s\",\"online_time\":%lu},", v19, *((_DWORD *)v19 + 57));
      if ( v21 >= a2 - v10 )
        v21 = a2 - v10 - 1;
      v10 += v21;
      ++v20;
      if ( v10 >= a2 - 49 )
        break;
      v19 += 292;
    }
    while ( v20 < v8[5] );
LABEL_21:
    if ( v10 > 0 )
    {
      v9 = v10;
      if ( *(_BYTE *)(a1 + v10 - 1) != 44 )
        goto LABEL_4;
      --v10;
    }
    v9 = v10;
    goto LABEL_4;
  }
LABEL_3:
  v9 = 0;
  v10 = 0;
LABEL_4:
  *(_BYTE *)(a1 + v9) = 0;
  _mem_free(v8);
  return v10;
}
// 49F9E4: variable 'v6' is possibly undefined
// 49FA08: variable 'v7' is possibly undefined
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

