int __fastcall asp_lipp(char *a1)
{
  char *v2; // $v0
  char *v3; // $v0
  char v5[68]; // [sp+18h] [-44h] BYREF

  v2 = (char *)nvram_get("lan_ipaddr");
  if ( !v2 )
    return 0;
  strcpy(v5, v2);
  v3 = strrchr(v5, 46);
  if ( v3 )
    *v3 = 0;
  return sprintf(a1, "%s", v5);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

