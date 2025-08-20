# Венгерская нотация для проекта BuksanSpy

## Что уже сделано:

### 1. Переименованы файлы:
- `buksanspy.h` → `CBuksanSpy.h`
- `accessmanager.h` → `CAccessManager.h`
- `adddevice.h` → `CAddDevice.h`
- `authorization.h` → `CAuthorization.h`
- `buksanspyapp.h` → `CBuksanSpyApp.h`
- `buksanviewfinder.h` → `CBuksanViewFinder.h`
- `cameravideocapture.h` → `CCameraVideoCapture.h`
- `checkconnection.h` → `CCheckConnection.h`
- `checkstring.h` → `CCheckString.h`
- `createuser.h` → `CCreateUser.h`
- `databaseconnection.h` → `CDatabaseConnection.h`
- `datacryptor.h` → `CDataCryptor.h`
- `devices.h` → `CDevices.h`
- `editmandatorygroup.h` → `CEditMandatoryGroup.h`
- `eventlog.h` → `CEventLog.h`
- `mandatorygroups.h` → `CMandatoryGroups.h`
- `mandatorymarkcreator.h` → `CMandatoryMarkCreator.h`
- `mandatorymarkseditor.h` → `CMandatoryMarksEditor.h`
- `networkinfo.h` → `CNetworkInfo.h`
- `sendalert.h` → `CSendAlert.h`
- `users.h` → `CUsers.h`

### 2. Обновлен файл проекта:
- `BuksanSpy.pro` - все имена файлов обновлены

### 3. Обновлены основные файлы:
- `main.cpp` - все переменные и функции переименованы
- `CBuksanSpy.h` - класс и переменные обновлены
- `CBuksanSpy.cpp` - все имена обновлены
- `CAccessManager.h` - класс и функции обновлены
- `CAccessManager.cpp` - все имена обновлены
- `CAddDevice.h` - класс и переменные обновлены
- `CAddDevice.cpp` - все имена обновлены

## Правила венгерской нотации для проекта:

### Классы:
- Префикс `C` + PascalCase: `CBuksanSpy`, `CAccessManager`

### Переменные:
- `m_` для членов класса: `m_pUi`, `m_strUsername`
- `g_` для глобальных: `g_strUsername`
- `l_` для локальных: `l_strResult`, `l_nValue`

### Префиксы типов:
- `str` для QString: `m_strUsername`
- `n` для int: `m_nCamc`
- `p` для указателей: `m_pUi`
- `b` для bool: `m_bIsRecording`

### Функции:
- `f` + PascalCase: `fSetTitle()`, `fCheckRights()`

## Что нужно сделать дальше:

### 1. Обновить все остальные заголовочные файлы:
- Обновить `#ifndef`, `#define`, `#endif`
- Переименовать классы
- Обновить переменные-члены

### 2. Обновить все .cpp файлы:
- Обновить включения заголовочных файлов
- Обновить имена классов в конструкторах/деструкторах
- Обновить все переменные и функции

### 3. Обновить .ui файлы:
- Обновить имена классов в UI файлах

### 4. Проверить компиляцию:
- Убедиться, что проект собирается без ошибок
- Исправить все ошибки компиляции

## Команды для быстрого обновления:

```bash
# Обновить все заголовочные файлы
for file in *.h; do
    echo "Обновление $file..."
    # Обновить #ifndef, #define, #endif
    # Переименовать классы
    # Обновить переменные
done

# Обновить все .cpp файлы
for file in *.cpp; do
    echo "Обновление $file..."
    # Обновить включения
    # Обновить имена классов
    # Обновить переменные
done
```

## Важные замечания:

1. **Сохраняйте резервные копии** перед массовыми изменениями
2. **Обновляйте файлы по одному** и проверяйте компиляцию
3. **Используйте поиск и замену** для массовых изменений
4. **Проверяйте зависимости** между файлами
5. **Обновляйте UI файлы** после обновления классов

## Статус проекта:
- ✅ Основные файлы обновлены
- 🔄 В процессе обновления остальных файлов
- ⏳ Требуется обновление всех заголовочных файлов
- ⏳ Требуется обновление всех .cpp файлов
- ⏳ Требуется обновление всех .ui файлов
- ⏳ Требуется проверка компиляции
