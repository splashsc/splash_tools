int get_nonce()
{
  const char *v0; // $v0
  const char *v1; // $s0
  bool v2; // dc
  int result; // $v0
  int v4; // $s0

  v0 = (const char *)nvram_get("ai_qrcode_nonce");
  if ( !v0 || (v1 = v0, v2 = strlen(v0) < 5, result = (int)v1, v2) )
  {
    v4 = GenerateStr();
    nvram_set("ai_qrcode_nonce", v4);
    result = v4;
  }
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84F4: using guessed type int GenerateStr(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

