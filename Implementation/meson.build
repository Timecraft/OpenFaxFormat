# Define Project
project (   'off_reference_implementation',# Name
            'vala', 'c', # Language(s)
            version: '2021.03.03' # Version number (IS08601 (YYYY.MM.DD))
        )
        
# Get C Compiler
cc = meson.get_compiler ('c')

# Define dependencies

dependencies = [
    dependency ('gtk+-3.0'),
    dependency ('granite'),
    dependency ('libsoup-2.4'),
    dependency ('cairo'),
    dependency ('glib-2.0'),
    dependency ('gio-2.0'),
    dependency ('poppler-glib'),
    cc.find_library ('m')       # Math lib
]

# Enter `src` directory
subdir ('src')

