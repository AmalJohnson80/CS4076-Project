#include <QtWidgets>

class RecipeApp : public QMainWindow {
public:
    RecipeApp() {
        // Create the main window
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        // Create the menu bar
        QMenuBar *menuBar = new QMenuBar(this);
        setMenuBar(menuBar);

        QMenu *fileMenu = new QMenu("File", this);
        menuBar->addMenu(fileMenu);
        fileMenu->addAction("Open");
        fileMenu->addAction("Save");
        fileMenu->addSeparator();
        fileMenu->addAction("Exit", this, &RecipeApp::close);

        QMenu *editMenu = new QMenu("Edit", this);
        menuBar->addMenu(editMenu);
        editMenu->addAction("Cut");
        editMenu->addAction("Copy");
        editMenu->addAction("Paste");

        // Create the recipe list
        QListWidget *recipeList = new QListWidget(centralWidget);

        // Create the recipe details display
        QGridLayout *recipeDetailsLayout = new QGridLayout();
        QLabel *recipeTitleLabel = new QLabel("Select a recipe", centralWidget);
        recipeTitleLabel->setAlignment(Qt::AlignCenter);
        recipeDetailsLayout->addWidget(recipeTitleLabel, 0, 0);
        QLabel *recipeDetailsLabel = new QLabel("", centralWidget);
        recipeDetailsLayout->addWidget(recipeDetailsLabel, 1, 0);

        // Create the filtering options
        QCheckBox *veganCheckbox = new QCheckBox("Vegan", centralWidget);
        QCheckBox *vegetarianCheckbox = new QCheckBox("Vegetarian", centralWidget);
        QRadioButton *indianRadio = new QRadioButton("Indian", centralWidget);
        QRadioButton *italianRadio = new QRadioButton("Italian", centralWidget);

        // Create the ingredient quantity adjustment slider
        QSlider *ingredientSlider = new QSlider(Qt::Horizontal, centralWidget);
        ingredientSlider->setMinimum(0);
        ingredientSlider->setMaximum(100);

        // Add all the widgets to the main window
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);
        layout->addWidget(recipeList);
        layout->addLayout(recipeDetailsLayout);
        layout->addWidget(veganCheckbox);
        layout->addWidget(vegetarianCheckbox);
        layout->addWidget(indianRadio);
        layout->addWidget(italianRadio);
        layout->addWidget(new QLabel("Adjust ingredient quantity:", centralWidget));
        layout->addWidget(ingredientSlider);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RecipeApp window;
    window.show();
    return app.exec();
}
