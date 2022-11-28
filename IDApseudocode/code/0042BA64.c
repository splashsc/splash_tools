int __fastcall sub_42BA64(int a1)
{
  *(_DWORD *)(a1 + 205576) = 0;
  *(_DWORD *)(a1 + 205572) = 0;
  exec_service_timeout(a1);
  return 0;
}

