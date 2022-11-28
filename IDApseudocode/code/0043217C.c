int __fastcall sub_43217C(int a1)
{
  const char *v2; // $s1
  size_t v3; // $v0
  char *v4; // $v0
  int v5; // $v0
  int result; // $v0
  char v7[128]; // [sp+18h] [-80h] BYREF

  if ( (*(_DWORD *)(a1 + 32) & 0x200) == 0 )
    goto LABEL_9;
  v2 = (const char *)(*(_DWORD *)(a1 + 205508) + 6);
  if ( !strstr(*(const char **)(a1 + 205508), "Basic") )
    goto LABEL_9;
  v3 = strlen(v2);
  v7[base64_decode(v2, v7, v3)] = 0;
  v4 = strchr(v7, 58);
  if ( v4 )
    *v4++ = 0;
  v5 = httpd_user_check(a1, v7, v4);
  if ( v5 < 0 )
  {
    *(_BYTE *)(a1 + 43) = 3;
    httpd_send_realm_admin(a1);
    return -1;
  }
  if ( !v5 )
  {
LABEL_9:
    *(_BYTE *)(a1 + 43) = 3;
    httpd_send_realm(a1);
    return -1;
  }
  *(_DWORD *)(a1 + 205588) = v5;
  result = 0;
  *(_BYTE *)(a1 + 43) = 1;
  return result;
}
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);

