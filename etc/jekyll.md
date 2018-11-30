# Jekyll을 이용한 GitHub Blog 만들기

- [이재열님](https://github.com/malkoG)의 강의를 토대로 만들어진 매뉴얼입니다.

### 목차
1. 설치 
    1. Git
    2. Ruby
    3. VS Code
2. 배포하기
    1. post
    2. publish
3. 커스터마이징
    1. 댓글 기능

### [Jekyll](#목차)





### [GitHub](#목차)
### [환경 설정](#목차)

[Git 설치](https://git-scm.com/)

![Image](https://i.imgur.com/T56GzYB.png)

- 재열님은 아래 이외에는 모두 Next 하셨습니다.
    - Use Git from Git bash only.     
    - Unix Style line endings.
    - Enable Symbolic Link 체크

[Ruby 설치 링크](https://www.ruby-lang.org/ko/)


![Image](https://i.imgur.com/GMJU4R8.png)

- RubyInstaller
![Image](https://i.imgur.com/Dorau1u.png)

- 맨 위 2.5.3-1 설치 
![Image](https://i.imgur.com/mNUSgcY.png)

- 다 체크 후 설치

![Image](https://i.imgur.com/AyEyTvl.png)

- 커맨드 창이 나오는데, 3을 입력해서 설치한다.
![Image](https://i.imgur.com/sBHd7nJ.png)

### [Visual Studio Code 설치 링크](https://code.visualstudio.com/)

### Jekyll 설치
- `Ctrl` + ``` ` ```(물결)을 누르면 터미널이 나온다.
- 우측 아래 Customize 버튼을 누르면 Git Bash를 고른다.
- 한번 껐다 켠다.
- 다시 터미널을 열고 `gem install jekyll`을 입력한다.

![Image](https://i.imgur.com/2bRiBaJ.png)

- 설치가 다 됐으면 `Jekyll new 자신의 블로그 이름`을 입력한다
- (선택) 추천 Extension
    - Project Manager
    - VS Color Picker

![Image](https://i.imgur.com/3FxAwbw.png)

![Image](https://i.imgur.com/8uvmE0o.png)

![Image](https://i.imgur.com/XHGSlyU.png)

`jekyll new 계정명.github.io`

![Image](https://i.imgur.com/Nt1NqqK.png)

cd 
![Image](https://i.imgur.com/gNT6ESo.png)

- VS Code의 `File` - `Open Folder`에서 터미널의 경로로 들어가 폴더를 연다.
- 터미널을 다시 연 후 `gem install bundler`를 입력한다.

![Image](https://i.imgur.com/RK80x6Q.png)

- `bundle install`을 입력한다.

![Image](https://i.imgur.com/jH2hprj.png)

- `jekyll serve`를 입력한다.

![Image](https://i.imgur.com/UvfTJsZ.png)

- 컨트롤 키를 누르고 링크를 클릭하면 기본 세팅된 블로그를 볼 수 있다.

![Image](https://i.imgur.com/4T0wQSh.png)

- `Ctrl` + `C`를 눌러 서버를 멈출 수 있다.

- `gem install jekyll-admin`

> `_config.yml` 수정 
```
# Welcome to Jekyll!
#
# This config file is meant for settings that affect your whole blog, values
# which you are expected to set up once and rarely edit after that. If you find
# yourself editing this file very often, consider using Jekyll's data files
# feature for the data you need to update frequently.
#
# For technical reasons, this file is *NOT* reloaded automatically when you use
# 'bundle exec jekyll serve'. If you change this file, please restart the server process.

# Site settings
# These are used to personalize your new site. If you look in the HTML files,
# you will see them accessed via {{ site.title }}, {{ site.email }}, and so on.
# You can create any custom variable you would like, and they will be accessible
# in the templates via {{ site.myvariable }}.
title: Your awesome title
email: your-email@example.com
description: >- # this means to ignore newlines until "baseurl:"
  Write an awesome description for your new site here. You can edit this
  line in _config.yml. It will appear in your document head meta (for
  Google search results) and in your feed.xml site description.
baseurl: "" # the subpath of your site, e.g. /blog
url: "" # the base hostname & protocol for your site, e.g. http://example.com
twitter_username: jekyllrb
github_username:  jekyll

# Build settings
markdown: kramdown
theme: minima
plugins:
  - jekyll-feed
  - jekyll-admin
# Exclude from processing.
# The following items will not be processed, by default. Create a custom list
# to override the default setting.
# exclude:
#   - Gemfile
#   - Gemfile.lock
#   - node_modules
#   - vendor/bundle/
#   - vendor/cache/
#   - vendor/gems/
#   - vendor/ruby/
```

> `gemfile` 수정
```md
source "https://rubygems.org"

# Hello! This is where you manage which Jekyll version is used to run.
# When you want to use a different version, change it below, save the
# file and run `bundle install`. Run Jekyll with `bundle exec`, like so:
#
#     bundle exec jekyll serve
#
# This will help ensure the proper Jekyll version is running.
# Happy Jekylling!
gem "jekyll", "~> 3.8.5"

# This is the default theme for new Jekyll sites. You may change this to anything you like.
gem "minima", "~> 2.0"

# If you want to use GitHub Pages, remove the "gem "jekyll"" above and
# uncomment the line below. To upgrade, run `bundle update github-pages`.
# gem "github-pages", group: :jekyll_plugins

# If you have any plugins, put them here!
group :jekyll_plugins do
    gem "jekyll-feed", "~> 0.6"
    gem install jekyll-admin
end

# Windows does not include zoneinfo files, so bundle the tzinfo-data gem
gem "tzinfo-data", platforms: [:mingw, :mswin, :x64_mingw, :jruby]

# Performance-booster for watching directories on Windows
gem "wdm", "~> 0.1.0" if Gem.win_platform?
```

#### 배포
