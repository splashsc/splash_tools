int __fastcall sub_42CB90(int a1, int a2)
{
  *(&array_conn.events + 4 * a2) = 5;
  return 0;
}

