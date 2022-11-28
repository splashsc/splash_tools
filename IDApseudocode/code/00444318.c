int __fastcall get_lan_vlan_data(char *a1, int a2)
{
  int v4; // $s2
  char *v5; // $v0
  int result; // $v0
  int v7; // $s1
  char *v8; // $v0
  char v9[64]; // [sp+20h] [-40h] BYREF

  memset(v9, 0, sizeof(v9));
  v4 = get_lans_num();
  v5 = (char *)nvram_get("lan_vlan");
  if ( !v5 )
  {
    v7 = 0;
    if ( v4 > 0 )
    {
      do
      {
        v8 = &v9[strlen(v9)];
        ++v7;
        *v8 = 49;
        v8[1] = 124;
        v8[2] = 0;
      }
      while ( v4 != v7 );
    }
    v5 = v9;
  }
  result = snprintf(a1, a2, "\"lan_num\":\"%d\",\"lan_vlan\":\"%s\"", v4, v5);
  if ( result >= a2 )
    result = a2 - 1;
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A87A0: using guessed type int get_lans_num(void);

