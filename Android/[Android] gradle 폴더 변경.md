### 은근히 용량 먹는 사용자 폴더 속 android 관련 폴더 경로 변경

- `Android Studio\bin\idea.properties` 들어가서 아래와 같이 바꾸면 됨(Line 9, Line 16)

```js
# Use ${idea.home.path} macro to specify location relative to IDE installation home.

# Use ${xxx} where xxx is any Java property (including defined in previous lines of this file) to refer to its value.
# Note for Windows users: please make sure you're using forward slashes (e.g. c:/idea/system).

#---------------------------------------------------------------------
# Uncomment this option if you want to customize path to IDE config folder. Make sure you're using forward slashes.
#---------------------------------------------------------------------
idea.config.path=E:/Program/Android/ETC/config

#---------------------------------------------------------------------
# Uncomment this option if you want to customize path to IDE system folder. Make sure you're using forward slashes.
#---------------------------------------------------------------------
idea.system.path=E:/Program/Android/ETC/system

```

- `.gradle` 경로 변경
`Setting` - `Build, Execution, Deployment` - `Gradle`에서 수정 가능하다.

![Image](https://i.imgur.com/6CnfNUr.png)