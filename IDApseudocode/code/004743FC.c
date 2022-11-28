int __fastcall sub_4743FC(int a1)
{
  char *v2; // $v0
  char *v3; // $v0
  int result; // $v0
  char v5[1028]; // [sp+18h] [-404h] BYREF

  memset(v5, 0, 0x400u);
  strlcpy(v5, *(_DWORD *)(a1 + 205536), 1024);
  v2 = strchr(v5, 44);
  if ( v2 )
    *v2 = 0;
  v3 = strchr(v5, 59);
  if ( v3 )
    *v3 = 0;
  result = strncmp(v5, "zh", 2u);
  if ( result )
    result = strncmp(v5, "en", 2u) == 0;
  return result;
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);

