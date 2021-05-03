# List source files
sources = [
    'Application.vala',
    
    # Widgets
    'widgets/MainWindow.vala',
    'widgets/IPEntry.vala',
    'widgets/FileChooser.vala',
    'widgets/Switch.vala',
    'widgets/SendButton.vala',
    
    # Structures
    'structures/Message.vala',
    'structures/ColorMessage.vala',
    'structures/SizeMessage.vala',
    'structures/PDFSource.vala',
    'structures/Messenger.vala',
    'structures/FileMessenger.vala',
    'structures/NetworkMessenger.vala',
    'structures/VersionMessage.vala'
]

# Define executable
#   Name
#   Sources
#   Dependencies
#   Install

executable (
    meson.project_name () + '_client',
    sources,
    dependencies: dependencies,
    install: false
)
