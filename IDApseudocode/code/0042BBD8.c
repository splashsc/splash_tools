int __fastcall websocket_respond_head(int a1)
{
  size_t v2; // $v0
  size_t v3; // $v0
  const char *v4; // $s0
  char *v5; // $v0
  int v6; // $v0
  char v8[10240]; // [sp+20h] [-308Ch] BYREF
  char v9[1024]; // [sp+2820h] [-88Ch] BYREF
  char v10[1024]; // [sp+2C20h] [-48Ch] BYREF
  char v11[128]; // [sp+3020h] [-8Ch] BYREF
  int v12[3]; // [sp+30A0h] [-Ch] BYREF

  v12[0] = 0;
  memset(v10, 0, sizeof(v10));
  memset(v9, 0, sizeof(v9));
  memset(v8, 0, sizeof(v8));
  if ( (*(_DWORD *)(a1 + 32) & 0x4F00000) == 0 )
    return -1;
  snprintf(v10, 1024, "%s%s", *(const char **)(a1 + 210000), "258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
  v2 = strlen(v10);
  v4 = (const char *)crypt_sha1(v10, v2, v12);
  v3 = strlen(v4);
  base64_encode(v4, v9, v3);
  v5 = GetDateString(v11, 0);
  v6 = snprintf(
         v8,
         10240,
         "HTTP/1.1 101 Switching Protocols\r\n"
         "Date: %s\r\n"
         "Connection: Upgrade\r\n"
         "Server: HTTPD_gw 1.0\r\n"
         "Expires: 0\r\n"
         "Upgrade: websocket\r\n"
         "Pragma: no-cache\r\n"
         "Cache-Control: no-cache\r\n"
         "Sec-WebSocket-Accept: %s\r\n"
         "\r\n",
         v5,
         v9);
  httpd_send_data_alloc(a1, v8, v6);
  return 0;
}
// 6A8304: using guessed type int __fastcall crypt_sha1(_DWORD, _DWORD, _DWORD);
// 6A8474: using guessed type int __fastcall base64_encode(_DWORD, _DWORD, _DWORD);

