project('backupd', 'c', 'cpp',
    version : '0.4.3',
    default_options : ['c_std=gnu11', 'cpp_std=c++14', 'buildtype=release'],
    meson_version : '>=0.53.0'
)

message('Using build type: ' + get_option('buildtype'))

force_velo_toolchain = get_option('force_velo_toolchain')

# TODO: Move this into meson's built in warning level.
add_project_arguments('-Wall', '-Werror', '-Wextra', language : 'c')
add_project_arguments('-Wall', '-Werror', '-Wextra', language : 'cpp')

flex = find_program('flex', required : true)
bison = find_program('bison', required : true)

src_not_main = run_command(
    'find', './src', '(', '-name', '*.c', '-or', '-name', '*.h' , ')', 
            '!', '-name', 'main.c',
    check : true
).stdout().strip().split('\n')

test_src = run_command(
    'find', './test', '-name', '*.cpp', '-or', '-name', '*.h',
    check : true
).stdout().strip().split('\n')

vcblockchain = dependency(
    'vcblockchain',
    required : true,
    fallback : ['vcblockchain', 'vcblockchain_dep']
)

vctool_sub = subproject('vctool')
vctool_include = vctool_sub.get_variable('vctool_include')
vctool = dependency(
    'vctool',
    required : true,
    fallback : ['vctool', 'vctool_dep']
)

cmake = import('cmake')
minunit_proj = cmake.subproject('minunit')
minunit = minunit_proj.dependency('minunit')

threads = dependency('threads')

backupd_include = include_directories('include')

backupd_exe = executable(
    'backupd',
    './src/backupd/main.c',
    src_not_main,
    include_directories : [backupd_include, vctool_include],
    dependencies : [threads, vcblockchain, vctool]
)

backupd_test = executable(
    'backupd-test',
    src_not_main, test_src,
    include_directories : [backupd_include, vctool_include],
    dependencies : [threads, vcblockchain, minunit]
)

test(
    'backupd-test',
    backupd_test,
)
