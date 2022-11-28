int __fastcall websocket_send_data(int a1, int a2, int a3)
{
  unsigned int v4; // $s0
  int v5; // $s2
  char v7; // [sp+18h] [-20004h] BYREF
  char v8; // [sp+19h] [-20003h]
  unsigned int v9; // [sp+1Ah] [-20002h]
  char v10; // [sp+1Eh] [-1FFFEh]
  char v11; // [sp+1Fh] [-1FFFDh]
  char v12; // [sp+20h] [-1FFFCh]
  char v13; // [sp+21h] [-1FFFBh]
  _BYTE v14[65540]; // [sp+10018h] [-10004h] BYREF

  v4 = jhl_str_to_utf8_max(a2, a3, v14, 0x10000);
  v7 = -127;
  if ( v4 < 0x7E )
  {
    v8 = v4;
    v5 = 2;
  }
  else if ( v4 < 0x10000 )
  {
    v8 = 126;
    LOWORD(v9) = htons(v4);
    v5 = 4;
  }
  else
  {
    htonl(v4);
    v8 = 127;
    v9 = v4;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = 0;
    v5 = 10;
  }
  memcpy(&v7 + v5, v14, v4);
  return httpd_send_data_alloc(a1, &v7, v5 + v4);
}
// 6A8880: using guessed type int __fastcall jhl_str_to_utf8_max(_DWORD, _DWORD, _DWORD, _DWORD);

