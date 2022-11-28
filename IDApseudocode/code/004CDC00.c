int mkdir(const char *path, __mode_t mode)
{
  MEMORY[0](path, mode);
  return cJSON_CodeString();
}
// 4CDC10: using guessed type int cJSON_CodeString(void);

