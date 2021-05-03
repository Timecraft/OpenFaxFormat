# List source files
sources = [
    'Application.vala',
    
    # Widgets
    'widgets/MainWindow.vala',
    'widgets/IPEntry.vala',
    'widgets/FileChooser.vala',
    'widgets/Switch.vala',
    'widgets/SendButton.vala',
    'widgets/DrawingArea.vala',
    
    # Structures
    'structures/Message.vala',
    'structures/ColorMessage.vala',
    'structures/SizeMessage.vala',
    'structures/PDFSource.vala',
    'structures/Messenger.vala',
    'structures/FileMessenger.vala',
    'structures/NetworkMessenger.vala',
    'structures/VersionMessage.vala',
    'structures/FileReader.vala',
    'structures/DrawCommand.vala'
]

# Define executable
#   Name
#   Sources
#   Dependencies
#   Install

executable (
    meson.project_name () + '_server',
    sources,
    dependencies: dependencies,
    install: false
)
