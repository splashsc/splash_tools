int __fastcall pppoe_br_user_get_state(char *a1, size_t a2)
{
  int *v4; // $v0
  int v5; // $a2
  int *v6; // $s0
  int v7; // $v0
  int v8; // $s7
  int *v10; // $s5
  int v11; // $s1
  int v12; // $a2
  char *v13; // $t3
  int v14; // $a3
  int v15; // $s6
  int v16; // $v0
  int v17; // $v0
  int v18; // $a2
  char v19[32]; // [sp+48h] [-60h] BYREF
  char v20[32]; // [sp+68h] [-40h] BYREF
  int v21; // [sp+88h] [-20h]
  char *v22; // [sp+8Ch] [-1Ch]
  char *v23; // [sp+90h] [-18h]
  int v24; // [sp+94h] [-14h]
  int v25; // [sp+98h] [-10h]
  char *v26; // [sp+9Ch] [-Ch]
  char *format; // [sp+A0h] [-8h]
  const char *v28; // [sp+A4h] [-4h]

  _mem_malloc(0x200000, "pppoe_br_user_get_state", 1650);
  v6 = v4;
  if ( !v4
    || (*v4 = 41, v4[3] = 10, v4[1] = 0x200000, jianhl_order_opt_fun(v4, 0x200000, v5))
    || (memset(a1, 0, a2), v10 = v6 + 12, v6[5] <= 0) )
  {
    v7 = 0;
    v8 = 0;
    goto LABEL_4;
  }
  v22 = "1\"";
  v8 = 0;
  v28 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
  v21 = a2 - 49;
  v11 = 0;
  v26 = "%u";
  format = "%u.%u";
  do
  {
    v18 = *((unsigned __int16 *)v10 - 8);
    if ( *((_WORD *)v10 - 7) )
    {
      sprintf(v19, format, v18);
      v12 = *((unsigned __int8 *)v10 - 23);
      v13 = &a1[v8];
      v14 = *((unsigned __int8 *)v10 - 24);
      v15 = a2 - v8;
      if ( v12 != 2 )
        goto LABEL_8;
    }
    else
    {
      sprintf(v19, v26, v18);
      v12 = *((unsigned __int8 *)v10 - 23);
      v13 = &a1[v8];
      v14 = *((unsigned __int8 *)v10 - 24);
      v15 = a2 - v8;
      if ( v12 != 2 )
      {
LABEL_8:
        v25 = v12;
        v24 = v14;
        v23 = v13;
        v16 = MacToStr(v20, (char *)v10 - 22);
        v13 = v23;
        v14 = v24;
        v12 = v25;
        goto LABEL_9;
      }
    }
    v16 = (int)(v28 - 1556);
LABEL_9:
    v17 = snprintf(
            v13,
            v15,
            v22 - 15024,
            v14,
            v10,
            v12,
            v16,
            *(v10 - 2),
            *(v10 - 1),
            v10 + 32,
            *(v10 - 3),
            v19,
            v10 + 64,
            v10 + 72,
            v10 + 80);
    if ( v17 >= v15 )
      v17 = v15 - 1;
    v8 += v17;
    ++v11;
    if ( v8 >= v21 )
      break;
    v10 += 94;
  }
  while ( v11 < v6[5] );
  if ( v8 <= 0 )
    goto LABEL_19;
  v7 = v8;
  if ( a1[v8 - 1] == 44 )
  {
    --v8;
LABEL_19:
    v7 = v8;
  }
LABEL_4:
  a1[v7] = 0;
  _mem_free(v6);
  return v8;
}
// 49D38C: variable 'v4' is possibly undefined
// 49D3B0: variable 'v5' is possibly undefined
// 6A88C8: using guessed type int __fastcall MacToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

