project('kun', 'c',
       version: '0.0.1')

glib2_dep = dependency('glib-2.0')

# all kun app should add to the list, format: [name, [src list]]
kun_apps = []
inc_kun = []

subdir('arch')
subdir('include')
subdir('lib')

subdir('src')


foreach app : kun_apps
  name = app[0]
  srcs = app[1]
  executable(
    name,
    srcs,
    dependencies: glib2_dep,
    include_directories: inc_kun,
    link_with: lib_kun, 
  )
endforeach
