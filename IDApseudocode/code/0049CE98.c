int __fastcall pppoe_br_session_get_state(int a1, int a2)
{
  int *v4; // $v0
  int v5; // $a2
  int *v6; // $s3
  bool v7; // dc
  int v8; // $v0
  char *v9; // $s7
  int v10; // $s0
  int v11; // $s2
  int v12; // $v0
  int v13; // $v0
  int v14; // $a3
  int v15; // $a2
  char v17[32]; // [sp+48h] [-58h] BYREF
  char v18[32]; // [sp+68h] [-38h] BYREF
  int v19; // [sp+88h] [-18h]
  int v20; // [sp+8Ch] [-14h]
  char *format; // [sp+90h] [-10h]
  char *v22; // [sp+94h] [-Ch]
  char *v23; // [sp+98h] [-8h]
  char *v24; // [sp+9Ch] [-4h]

  v24 = "1\"";
  _mem_malloc(0x200000, "pppoe_br_session_get_state", 1537);
  v6 = v4;
  if ( !v4 )
    goto LABEL_12;
  *v4 = 41;
  v4[3] = 12;
  v4[1] = 0x200000;
  v7 = jianhl_order_opt_fun(v4, 0x200000, v5) != 0;
  v8 = 0;
  if ( v7 )
  {
LABEL_13:
    v10 = 0;
    goto LABEL_14;
  }
  if ( v6[5] <= 0 )
  {
LABEL_12:
    v8 = 0;
    goto LABEL_13;
  }
  v20 = a2 - 49;
  v9 = (char *)v6 + 26;
  v23 = "%u";
  v10 = 0;
  format = "%u.%u";
  v11 = 0;
  v22 = "{\"session\":%u,\"mac\":\"%s\",\"user\":\"%s\",\"in_dev\":\"%s\",\"out_dev\":\"%s\",\"odate\":%u,\"qup\":%u,\"qd"
        "w\":%u,\"zup\":%u,\"zdw\":%u,\"mem\":\"%s\",\"vlan\":\"%s\",\"name\":\"%s\"},";
  do
  {
    v14 = *((unsigned __int16 *)v9 + 142);
    v15 = *((unsigned __int16 *)v9 + 141);
    if ( *((_WORD *)v9 + 142) )
      sprintf(v17, format, v15, v14);
    else
      sprintf(v17, v23, v15, v14);
    v19 = ntohs(*((_WORD *)v9 - 1));
    v12 = MacToStr(v18, v9);
    v13 = snprintf(
            (char *)(a1 + v10),
            a2 - v10,
            v22,
            v19,
            v12,
            v9 + 58,
            v9 + 6,
            v9 + 22,
            *(_DWORD *)(v9 + 38),
            *(_DWORD *)(v9 + 42),
            *(_DWORD *)(v9 + 46),
            *(_DWORD *)(v9 + 50),
            *(_DWORD *)(v9 + 54),
            v9 + 122,
            v17,
            v9 + 250);
    if ( v13 >= a2 - v10 )
      v13 = a2 - v10 - 1;
    v10 += v13;
    ++v11;
    if ( v10 >= v20 )
      break;
    v9 += 292;
  }
  while ( v11 < v6[5] );
  if ( v10 <= 0 )
    goto LABEL_18;
  v8 = v10;
  if ( *(_BYTE *)(a1 + v10 - 1) == 44 )
  {
    --v10;
LABEL_18:
    v8 = v10;
  }
LABEL_14:
  *(_BYTE *)(a1 + v8) = 0;
  _mem_free(v6);
  return v10;
}
// 49CF00: variable 'v4' is possibly undefined
// 49CF24: variable 'v5' is possibly undefined
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

