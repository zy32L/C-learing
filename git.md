#git 
##1. 安装与配置
(1) 安装命令如下：**sudo apt-get install git**
(2) 安装成功后运行**git**可看到常用的Git命令

##2. 创建一个版本库
(1) 新建一个目录git_test，在git_test目录下创建一个版本库，命令如下：**git init**
在git_test目录下创建了一个.git隐藏目录，这就是版本库目录。

##3. 版本创建与回退
###3.1使用
(1) 在git_test目录下创建一个文件例如code.txt，使用文本编辑器编辑

(2) 使用如下两条命令可以创建一个版本：
 **git add code.txt
git commit –m '版本1'**

(3)	使用如下命令可以查看版本记录：
**git log**

(4) 现在若想回到某一个版本，可以使用如下命令：
**git reset --hard HEAD^**
其中HEAD表示当前最新版本，HEAD^ 表示当前版本的前一个版本,HEAD^^ 表示当前版本的前前个版本，也可以使用HEAD~1 表示当前版本的前一个版本,HEAD~100 表示当前版本的前100版本。
也可以执行命令**git log**查看版本记录，使用命令**git reset --hard 版本号** (版本号很长，只要复制前几位就行)

(5) 假如终端已经关闭，再次打开终端后，想要版本回退，可以执行命令**git reflog**查看我们之前的操作记录，这样就能看到之前的版本号了

###3.2 工作区和暂存区
所有git add命令是把所有提交的修改存放到暂存区。
然后，执行git commit就可以一次性把暂存区的所有修改提交到分支创建一个版本。git管理的文件的修改，它只会提交暂存区的修改来创建版本。

(1)把文件往git版本库里添加的时候，是分两步执行的：
第一步是用**git add 文件名**(文件名之间空格)把文件添加进去，就是把文件修改添加到暂存区；
第二步是用**git commit**(-m ‘说明内容’)提交更改，就是把暂存区的所有内容提交到当前分支。

(2)	使用如下命令查看当前工作树的状态：**git status**

(3)	一旦提交后，如果你又没有对工作区做任何修改，那么工作区就是“干净”的。

###3.3 撤销修改
(1)使用 **git checkout -- <文件>** 来丢弃工作区的改动。

(3)用用命令**git reset HEAD file**可以把暂存区的修改撤销掉，重新放回工作区。

如果你不但改错了东西，还从暂存区提交到了版本库，则需要进行版本回退。

###3.4 对比文件不同
(1)	要对比工作区中code.txt和HEAD版本中code.txt的不同。使用如下命令：**git diff HEAD –- code.txt**
-表示HEAD版本 +表示工作区版本

(1)	现在要对比HEAD和HEAD^版本中code.txt的不同，使用如下命令：
**git diff HEAD ^HEAD – code.txt**
-表示HEAD版本 +表示HEAD^版本

###3.5 删除文件
(1) 我们把目录中的code2.txt删除: **rm code.txt**  这个时候，git知道删除了文件，因此，工作区和版本库就不一致了，**git status** 命令会立刻提示哪些文件被删除了。

(2)	现在你有两个选择，一是确实要从版本库中删除该文件，那就用命令**git rm**删掉，并且git commit：
**git commit -m ‘版本信息’**

另一种情况是删错了，可以直接使用**git checkout – code2.txt**,这样文件code2.txt又回来了。

##4. 分支管理
###4.1 创建与合并分支
(1)	执行如下命令可以查看当前有几个分支并且看到在哪个分支下工作：**Git branch**

(2)	下面创建一个分支dev并切换到其上进行工作：**Git checkout -b dev**

(3)	dev分支的工作完成，我们就可以切换回master分支：**git checkout master**


(4)	把dev分支的工作成果合并到master(当前)分支上：**git merge dev**

注意到Fast-forward信息，Git告诉我们，这次合并是“快进模式”，也就是直接把master指向dev的当前提交，所以合并速度非常快。

(5)可以删除dev分支了，删除后，查看branch，就只剩下master分支了:**git checkout -d dev**

###4.2 解决冲突
git无法执行“快速合并”，只能试图把各自的修改合并起来，但这种合并就可能会有冲突。

(1)	执行如下命令尝试将dev分支合并到master分支上来:**git merge dev**

git告诉我们，code.txt文件存在冲突，必须手动解决冲突后再提交。**git status**也可以告诉我们冲突的文件。

(2)查看code.txt的内容。git用<<<<<<<，=======，>>>>>>>标记出不同分支的内容，我们修改后保存：

(11)用带参数的git log也可以看到分支的合并情况：**Git log –-graph –pretty=oneline**

(12)工作完成后，可以删除dev分支。
**git checkout -d dev**



###4.3 Bug分支
当你接到一个修复一个代号001的bug的任务时，你想创建一个分支bug-001来修复它，但是，当前正在dev上进行的工作还没有提交：

(1)git提供了一个stash功能，可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作：**git stash**

(3)	首先确定要在哪个分支上修复bug，假定需要在master分支上修复，就从master创建临时分支：**git checkout master
Git checkout -b bug-001**

(4)	现在修复bug,把 the new line删掉，然后提交。
**git add code.txt
git commit -m ‘修复bug-001’**

(5)	修复完成后，切换到master分支，并完成合并，最后删除bug-001分支。Git checkout master
Git branch -d bug-001

(6)现在bug-001修复完成，是时候接着回到dev分支干活了.工作区是干净的，刚才的工作现场存到哪去了？用**git stash list**命令查看

工作现场还在，git把stash内容存在某个地方了，但是需要恢复一下.
执行命令**git stash pop**
